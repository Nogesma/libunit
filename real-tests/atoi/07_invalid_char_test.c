/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_invalid_char_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivautrav <ivautrav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:27:16 by msegrans          #+#    #+#             */
/*   Updated: 2023/02/11 20:11:22 by ivautrav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	invalid_char_test(void)
{
	if (ft_atoi("aaa b c 42a") == 42)
		return (0);
	return (-1);
}
