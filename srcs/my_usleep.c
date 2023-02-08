/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:01:07 by saguesse          #+#    #+#             */
/*   Updated: 2023/02/08 23:47:56 by saguesse         ###   ########.fr       */
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
		{
			pthread_mutex_lock(&p->data->death);
			p->data->died = 1;
			pthread_mutex_unlock(&p->data->death);
			print_msg(p, "died");
			return (1);
		}
		usleep(50);
	}
	return (0);
}
