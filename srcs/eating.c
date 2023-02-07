/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:12:20 by saguesse          #+#    #+#             */
/*   Updated: 2023/02/08 00:09:31 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	start_eating(t_philo *p)
{
	pthread_mutex_lock(&p->mutex);
	if (!p->data->forks[p->left] && !p->data->forks[p->right])
	{
		printf("%ld %ld has taken a fork\n", now() - p->start, p->index);
		printf("%ld %ld has taken a fork\n", now() - p->start, p->index);
		p->data->forks[p->left] = 1;
		p->data->forks[p->right] = 1;
		p->start_eating = now();
		printf("%ld %ld is eating\n\n", now() - p->start, p->index);
		if (p->data->number_eat)
			p->data->eat_count[p->index - 1]++;
	}
	pthread_mutex_unlock(&p->mutex);
}

void	finish_eating(t_philo *p)
{
	pthread_mutex_lock(&p->mutex);
	p->data->forks[p->left] = 0;
	p->data->forks[p->right] = 0;
	pthread_mutex_unlock(&p->mutex);
}
