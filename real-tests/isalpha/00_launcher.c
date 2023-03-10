/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivautrav <ivautrav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:46:08 by msegrans          #+#    #+#             */
/*   Updated: 2023/02/11 20:14:53 by ivautrav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libunit.h>

int	alpha_test(void);
int	not_alpha_test(void);

int	isalpha_launcher(void)
{
	t_unit_test	testlist;

	init_test(&testlist, "ISALPHA");
	load_test(&testlist, "alpha", &alpha_test);
	load_test(&testlist, "not alpha", &not_alpha_test);
	return (launch_tests(&testlist));
}
