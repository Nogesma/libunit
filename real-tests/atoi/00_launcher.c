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

int	atoi_basic_test(void);
int	atoi_negative_test(void);
int	atoi_sign_test(void);
int	atoi_whitespace_test(void);
int	atoi_maxint_test(void);
int	atoi_minint_test(void);
int	atoi_invalid_char_test(void);
int	atoi_zero_test(void);
int	atoi_one_test(void);
int	atoi_minus_one_test(void);

int	atoi_launcher(void)
{
	t_unit_test	testlist;

	init_test(&testlist, "ATOI");
	load_test(&testlist, "Simple", &atoi_basic_test);
	load_test(&testlist, "Negative", &atoi_negative_test);
	load_test(&testlist, "Positive", &atoi_sign_test);
	load_test(&testlist, "Whitespace", &atoi_whitespace_test);
	load_test(&testlist, "Max Int", &atoi_maxint_test);
	load_test(&testlist, "Min Int", &atoi_minint_test);
	load_test(&testlist, "Invalid char", &atoi_invalid_char_test);
	load_test(&testlist, "Zero", &atoi_zero_test);
	load_test(&testlist, "One", &atoi_one_test);
	load_test(&testlist, "Minus one", &atoi_minus_one_test);
	return (launch_tests(&testlist));
}
