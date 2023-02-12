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

#include <unistd.h>

int	sigpipe_test(void)
{
	int	fd[2];

	pipe(fd);
	close(fd[0]);
	write(fd[1], "Hello world!", 13);
	return (0);
}
