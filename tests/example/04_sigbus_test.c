/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_null_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msegrans <msegrans@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:51:40 by msegrans          #+#    #+#             */
/*   Updated: 2023/02/11 16:51:42 by msegrans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	sigbus_test(void)
{
	char	*s;

	s = "string";
	*s = 'a';
	return (0);
}
