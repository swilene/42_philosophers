/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:01:07 by saguesse          #+#    #+#             */
/*   Updated: 2023/02/06 17:55:29 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	my_usleep(t_philo *p, int time)
{
	size_t	s;

	gettimeofday(&p->now, NULL);
	s = (p->now.tv_usec - p->start.tv_usec) / 1000;
	while (s < (size_t)time)
	{
		usleep(1000);
		gettimeofday(&p->now, NULL);
		if ((size_t)((p->now.tv_usec - p->start_eating.tv_usec) / 1000)
				>= p->data->time_to_die)
		{
			pthread_mutex_lock(&p->mutex);
			printf("%ld %ld died\n", (p->now.tv_usec - p->start.tv_usec) / 1000,
				p->index);
			pthread_mutex_unlock(&p->mutex);
			return (1);
		}
	}
	return (0);
}
