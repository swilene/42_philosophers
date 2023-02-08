/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:16:59 by saguesse          #+#    #+#             */
/*   Updated: 2023/02/08 15:01:50 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	thinking(t_philo *p)
{
	size_t	t;

	t = now();
	pthread_mutex_lock(&p->mutex);
	if (!p->data->death)
		printf("%ld %ld is thinking\n", t - p->start, p->index);
	pthread_mutex_unlock(&p->mutex);
	while (now() - t < (size_t)p->data->time_to_die)
	{
		if (!p->data->forks[p->left] && !p->data->forks[p->right])
			break ;
		usleep(50);
	}
}
