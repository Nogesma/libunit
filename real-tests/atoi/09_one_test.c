/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_one_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msegrans <msegrans@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:28:54 by msegrans          #+#    #+#             */
/*   Updated: 2023/02/12 15:28:56 by msegrans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	atoi_one_test(void)
{
	if (ft_atoi("1") == 1)
		return (0);
	return (-1);
}
