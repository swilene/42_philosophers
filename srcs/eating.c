/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:12:20 by saguesse          #+#    #+#             */
/*   Updated: 2023/02/03 18:47:15 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	start_eating(t_philo *p)
{
	pthread_mutex_lock(&p->mutex);
	if (!p->data->forks[p->left] && !p->data->forks[p->right])
	{
		gettimeofday(&p->now, NULL);
		printf("%ld %ld has taken a fork\n", (p->now.tv_usec
				- p->data->start.tv_usec) / 1000, p->index);
		printf("%ld %ld has taken a fork\n", (p->now.tv_usec
				- p->data->start.tv_usec) / 1000, p->index);
		p->data->forks[p->left] = 1;
		p->data->forks[p->right] = 1;
		printf("%ld %ld is eating\n\n", (p->now.tv_usec
				- p->data->start.tv_usec) / 1000, p->index);
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
