/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivautrav <ivautrav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:02:32 by msegrans          #+#    #+#             */
/*   Updated: 2023/02/11 18:35:58 by ivautrav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include <libft.h>
#include <sys/wait.h>

void	print_total(int ok, int len);
void	print_result(int ret);

void	load_test(t_unit_test *tests, char *description, int (*fn)(void))
{
	t_test	*t;
	t_list	*new;

	t = malloc(sizeof(t_test));
	if (t == NULL)
		return ;
	t->description = description;
	t->fn = fn;
	new = ft_lstnew(t);
	if (!new)
		return ;
	ft_lstadd_back(&tests->tests, new);
}

int	test(char *name, t_test *t)
{
	pid_t	child;
	int		ret;

	child = fork();
	if (child == -1)
		return (child);
	if (child == 0)
	{
		close(1);
		ret = t->fn();
		exit(ret);
	}
	wait(&ret);
	ft_putstr_fd(name, 1);
	ft_putstr_fd(": ", 1);
	ft_putstr_fd(t->description, 1);
	print_result(ret);
	if (WIFSIGNALED(ret))
		return (-1);
	return (WEXITSTATUS(ret));
}

void	init_test(t_unit_test *tests, char *name)
{
	tests->name = name;
	tests->tests = NULL;
}

int	launch_tests(t_unit_test *tests)
{
	t_list	*lst;
	int		ret;
	int		ok;
	int		len;

	lst = tests->tests;
	ret = 0;
	ok = 0;
	len = 0;
	while (lst)
	{
		len++;
		ret = test(tests->name, lst->content);
		if (ret == 0)
			ok++;
		lst = lst->next;
	}
	print_total(ok, len);
	if (ok != len)
		return (-1);
	return (0);
}
