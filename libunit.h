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

typedef t_list	t_unit_test;

typedef struct s_test {
	char	*description;
	int		(*fn)(void);
}	t_test;

void	load_test(t_unit_test **tests, char *description, int (*fn)(void));

int		launch_tests(t_unit_test **tests);

#endif //LIBUNIT_H
