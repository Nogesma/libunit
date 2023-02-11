/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivautrav <ivautrav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:46:08 by msegrans          #+#    #+#             */
/*   Updated: 2023/02/11 20:17:42 by ivautrav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libunit.h>

int	itoa_ok_test(void);
int	itoa_basic_test(void);
int	itoa_minint_test(void);
int	itoa_maxint_test(void);

int	itoa_launcher(void)
{
	t_unit_test	testlist;

	init_test(&testlist, "ITOA");
	load_test(&testlist, "OK test", &itoa_ok_test);
	load_test(&testlist, "Basic test", &itoa_basic_test);
	load_test(&testlist, "Min Int test", &itoa_minint_test);
	load_test(&testlist, "Max Int test", &itoa_maxint_test);
	return (launch_tests(&testlist));
}
