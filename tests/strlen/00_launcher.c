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

int	basic_test(void);
int	null_test(void);

int	strlen_launcher(void)
{
	t_unit_test	*testlist;

	load_test(&testlist, "Basic test", &basic_test);
	load_test(&testlist, "NULL test", &null_test);
	return (launch_tests(&testlist));
}
