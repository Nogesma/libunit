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
#include <stdio.h>

void	load_test(t_unit_test **tests, char *description, int (*fn)(void))
{
	t_test		*t;
	t_unit_test	*new;

	t = malloc(sizeof(t_test));
	t->description = description;
	t->fn = fn;
	new = ft_lstnew(t);
	if (!new)
		return ;
	ft_lstadd_front(tests, new);
}

int	test(t_test *t)
{
	pid_t	child;
	int		ret;

	ft_putstr_fd("[]: ", 1);
	ft_putstr_fd(t->description, 1);
	child = fork();
	if (child == -1)
		return (child);
	if (child == 0)
	{
		ret = t->fn();
		exit(ret);
	}
	wait(&ret);
	if (WIFSIGNALED(ret))
	{
		if (WTERMSIG(ret) == SIGSEGV)
			ft_putendl_fd(": [SIGSEGV]", 1);
		else if (WTERMSIG(ret) == SIGBUS)
			ft_putendl_fd(": [BUS]", 1);
		else if (WTERMSIG(ret) == SIGABRT)
			ft_putendl_fd(": [SIGABRT]", 1);
		else if (WTERMSIG(ret) == SIGFPE)
			ft_putendl_fd(": [SIGFPE]", 1);
		else if (WTERMSIG(ret) == SIGPIPE)
			ft_putendl_fd(": [SIGPIPE]", 1);
		else if (WTERMSIG(ret) == SIGILL)
			ft_putendl_fd(": [SIGILL]", 1);
		else
			ft_putendl_fd(" : [ERR]", 1);
		return (1);
	}
	else
		ft_putendl_fd(": [OK]", 1);
	return (WEXITSTATUS(ret));
}

void	print_result(int ok, int len)
{
	char	*ok_str;
	char	*len_str;

	ok_str = ft_itoa(ok);
	len_str = ft_itoa(len);
	ft_putendl_fd("", 1);
	ft_putstr_fd(ok_str, 1);
	ft_putstr_fd("/", 1);
	ft_putstr_fd(len_str, 1);
	ft_putendl_fd(" tests checked", 1);
}

int	launch_tests(t_unit_test **tests)
{
	t_list	*lst;
	int		ret;
	int		ok;
	int		len;

	lst = *tests;
	ret = 0;
	ok = 0;
	len = 0;
	while (lst)
	{
		len++;
		ret = test(lst->content);
		if (ret == 0)
			ok++;
		lst = lst->next;
	}
	print_result(ok, len);
	return (ok != len);
}
