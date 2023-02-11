/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivautrav <ivautrav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:45:57 by msegrans          #+#    #+#             */
/*   Updated: 2023/02/11 20:18:46 by ivautrav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	atoi_launcher(void);
int	itoa_launcher(void);
int	isalpha_launcher(void);

int	main(void)
{
	int	ret;

	ret = 0;
	ret |= atoi_launcher();
	ret |= itoa_launcher();
	ret |= isalpha_launcher();
	return (ret);
}
