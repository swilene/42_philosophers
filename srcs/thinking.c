/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:16:59 by saguesse          #+#    #+#             */
/*   Updated: 2023/02/09 15:11:52 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	thinking(t_philo *p)
{
	pthread_mutex_lock(&p->data->mutex);
	printf("%ld %ld is thinking\n", now() - p->start, p->index);
	pthread_mutex_unlock(&p->data->mutex);
	while (1)
	{
		pthread_mutex_lock(&p->left->mutex_fork);
		pthread_mutex_lock(&p->right->mutex_fork);
		if (!p->left->forks && !p->right->forks)
		{
			pthread_mutex_unlock(&p->left->mutex_fork);
			pthread_mutex_unlock(&p->right->mutex_fork);
			break ;
		}
		pthread_mutex_unlock(&p->left->mutex_fork);
		pthread_mutex_unlock(&p->right->mutex_fork);
		usleep(50);
	}
}
