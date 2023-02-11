/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msegrans <msegrans@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:45:05 by msegrans          #+#    #+#             */
/*   Updated: 2023/02/11 18:45:06 by msegrans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include "libunit.h"

void	print_total(int ok, int len)
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

void	print_result(int ret)
{
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
	}
	else
	{
		if (WEXITSTATUS(ret) != 0)
			ft_putendl_fd(": [KO]", 1);
		else
			ft_putendl_fd(": [OK]", 1);
	}
}
