/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:01:07 by saguesse          #+#    #+#             */
/*   Updated: 2023/02/09 16:01:51 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	my_usleep(t_philo *p, int time)
{
	size_t	t;

	t = now();
	while (now() - t < (size_t)time)
	{
		if (now() - p->start_eating >= p->data->time_to_die)
			print_msg(p, "died", DIED);
		usleep(50);
	}
	return (0);
}
