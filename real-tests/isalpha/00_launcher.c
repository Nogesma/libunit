/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivautrav <ivautrav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:46:08 by msegrans          #+#    #+#             */
/*   Updated: 2023/02/11 19:53:06 by ivautrav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libunit.h>

int	isalpha_ok_test(void);
int	isalpha_ko_test(void);

int	isalpha_launcher(void)
{
	t_unit_test	testlist;

	init_test(&testlist, "ISALPHA");
	load_test(&testlist, "OK test", &isalpha_ok_test);
	load_test(&testlist, "KO test", &isalpha_ko_test);
	return (launch_tests(&testlist));
}
