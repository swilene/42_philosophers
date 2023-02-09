/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:12:20 by saguesse          #+#    #+#             */
/*   Updated: 2023/02/09 17:40:42 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	finish_eating(t_philo *p)
{
	pthread_mutex_lock(&p->left->mutex_fork);
	p->left->forks = 0;
	pthread_mutex_unlock(&p->left->mutex_fork);
	pthread_mutex_lock(&p->right->mutex_fork);
	p->right->forks = 0;
	pthread_mutex_unlock(&p->right->mutex_fork);
}

void	start_eating(t_philo *p)
{
	while (1)
	{
		if (now() - p->start_eating >= p->data->time_to_die)
		{
			print_msg(p, "died", DIED);
			break ;
		}
		pthread_mutex_lock(&p->left->mutex_fork);
		if (!p->left->forks)
		{
			p->left->forks = 1;
			pthread_mutex_unlock(&p->left->mutex_fork);
			print_msg(p, "has taken a fork", 0);
			break ;
		}
		pthread_mutex_unlock(&p->left->mutex_fork);
		usleep(50);
	}
	while (1)
	{
		if (now() - p->start_eating >= p->data->time_to_die)
		{
			print_msg(p, "died", DIED);
			break ;
		}
		pthread_mutex_lock(&p->right->mutex_fork);
		if (!p->right->forks)
		{
			p->right->forks = 1;
			pthread_mutex_unlock(&p->right->mutex_fork);
			print_msg(p, "has taken a fork", 0);
			break ;
		}
		pthread_mutex_unlock(&p->right->mutex_fork);
		usleep(50);
	}
	print_msg(p, "is eating", EAT);
	p->start_eating = now();
}
