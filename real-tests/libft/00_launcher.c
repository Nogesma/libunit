/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msegrans <msegrans@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:46:08 by msegrans          #+#    #+#             */
/*   Updated: 2023/02/11 16:46:10 by msegrans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libunit.h>

int	ok_test(void);
int	ko_test(void);
int	sigsegv_test(void);
int	sigbus_test(void);

#define NAME "STRLEN"

int	example_launcher(void)
{
	t_unit_test	testlist;

	init_test(&testlist, "EXAMPLE");
	load_test(&testlist, "OK test", &ok_test);
	load_test(&testlist, "KO test", &ko_test);
	load_test(&testlist, "SIGSEGV test", &sigsegv_test);
	load_test(&testlist, "SIGBUS test", &sigbus_test);
	return (launch_tests(&testlist));
}
