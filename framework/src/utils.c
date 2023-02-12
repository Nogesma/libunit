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

#define RESET "\033[0m"
#define BOLD "\033[1m"
#define RED "\033[31m"
#define GREEN "\033[32m"

void	print_total(int ok, int len)
{
	char	*ok_str;
	char	*len_str;

	ok_str = ft_itoa(ok);
	len_str = ft_itoa(len);
	ft_putstr_fd(BOLD, 1);
	ft_putstr_fd(ok_str, 1);
	ft_putstr_fd("/", 1);
	ft_putstr_fd(len_str, 1);
	ft_putstr_fd(" tests checked", 1);
	ft_putendl_fd(RESET, 1);
}

void	print_green(char *str)
{
	ft_putstr_fd(GREEN, 1);
	ft_putstr_fd(str, 1);
	ft_putstr_fd(RESET, 1);
}

void	print_red(char *str)
{
	ft_putstr_fd(RED, 1);
	ft_putstr_fd(str, 1);
	ft_putstr_fd(RESET, 1);
}

void	print_result(int ret)
{
	ft_putstr_fd(": [", 1);
	if (WIFSIGNALED(ret))
	{
		if (WTERMSIG(ret) == SIGSEGV)
			print_red("SIGSEGV");
		else if (WTERMSIG(ret) == SIGBUS)
			print_red("BUS");
		else if (WTERMSIG(ret) == SIGABRT)
			print_red("SIGABRT");
		else if (WTERMSIG(ret) == SIGFPE)
			print_red("SIGFPE");
		else if (WTERMSIG(ret) == SIGPIPE)
			print_red("SIGPIPE");
		else if (WTERMSIG(ret) == SIGILL)
			print_red("SIGILL");
		else
			print_red("ERR");
	}
	else if (WEXITSTATUS(ret) != 0)
		print_red("KO");
	else
		print_green("OK");
	ft_putendl_fd("]", 1);
}
