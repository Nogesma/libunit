/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivautrav <ivautrav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:46:08 by msegrans          #+#    #+#             */
/*   Updated: 2023/02/11 20:13:42 by ivautrav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libunit.h>

int	ok_test(void);
int	basic_test(void);
int	sign_test(void);
int	whitespace_test(void);
int	maxint_test(void);
int	minint_test(void);
int	invalid_char_test(void);

int	atoi_launcher(void)
{
	t_unit_test	testlist;

	init_test(&testlist, "ATOI");
	load_test(&testlist, "OK test", &ok_test);
	load_test(&testlist, "Basic test", &basic_test);
	load_test(&testlist, "Sign test", &sign_test);
	load_test(&testlist, "Whitespace test", &whitespace_test);
	load_test(&testlist, "Max Int test", &maxint_test);
	load_test(&testlist, "Min Int test", &minint_test);
	load_test(&testlist, "Invalid char test", &invalid_char_test);
	return (launch_tests(&testlist));
}
