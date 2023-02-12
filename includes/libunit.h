/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msegrans <msegrans@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:55:23 by msegrans          #+#    #+#             */
/*   Updated: 2023/02/11 14:55:27 by msegrans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H

# include <libft.h>

typedef struct s_unit_test {
	char	*name;
	t_list	*tests;
}	t_unit_test;

typedef struct s_test {
	char	*description;
	int		(*fn)(void);
}	t_test;

void	init_test(t_unit_test *tests, char *name);

void	load_test(t_unit_test *tests, char *description, int (*fn)(void));

int		launch_tests(t_unit_test *tests);

#endif //LIBUNIT_H
