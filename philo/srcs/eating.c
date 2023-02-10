/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:12:20 by saguesse          #+#    #+#             */
/*   Updated: 2023/02/10 10:10:50 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	take_fork(t_philo *p, t_fork *forks)
{
	while (1)
	{
		if ((int)(now() - p->start_eating) >= p->data->time_to_die)
		{
			print_msg(p, "died", DIED);
			break ;
		}
		pthread_mutex_lock(&forks->mutex_fork);
		if (!forks->forks)
		{
			forks->forks = 1;
			pthread_mutex_unlock(&forks->mutex_fork);
			print_msg(p, "has taken a fork", 0);
			break ;
		}
		pthread_mutex_unlock(&forks->mutex_fork);
		usleep(50);
	}
}

void	eating(t_philo *p)
{
	take_fork(p, p->left);
	take_fork(p, p->right);
	print_msg(p, "is eating", EAT);
	p->start_eating = now();
	my_usleep(p, p->data->time_to_eat);
	pthread_mutex_lock(&p->left->mutex_fork);
	p->left->forks = 0;
	pthread_mutex_unlock(&p->left->mutex_fork);
	pthread_mutex_lock(&p->right->mutex_fork);
	p->right->forks = 0;
	pthread_mutex_unlock(&p->right->mutex_fork);
}
