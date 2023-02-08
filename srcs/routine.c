/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:08:41 by saguesse          #+#    #+#             */
/*   Updated: 2023/02/09 00:19:52 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	philos(t_philo *p)
{
	while (!p->data->died)
	{
		eating(p);
		sleeping(p);
		my_usleep(p, p->data->time_to_sleep);
		thinking(p);
		usleep(10);
		//if everyone ate
		//	break;
	}
}

void	one_philo(t_philo *p)
{
	printf("%ld %ld has taken a fork\n", now() - p->start, p->index);
	my_usleep(p, p->data->time_to_die);
	printf("%ld %ld died\n", now() - p->start, p->index);
}

void	*routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	p->start = now();
	p->start_eating = now();
	if (p->data->nb_philo == 1)
	{
		one_philo(p);
		return (0);
	}
	if (p->index == p->data->nb_philo)
		p->right = 0;
	else
		p->right = p->index;
	p->left = p->index - 1;
	if (p->index % 2)
	{
		thinking(p);
		my_usleep(p, p->data->time_to_eat);
	}
	philos(p);
	return (0);
}
