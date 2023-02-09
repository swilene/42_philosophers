/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:08:41 by saguesse          #+#    #+#             */
/*   Updated: 2023/02/09 17:10:18 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_deaths(t_philo *p)
{
	pthread_mutex_lock(&p->data->mutex);
	if (p->data->died || (p->data->number_eat && p->data->eat_count
			== (int)p->data->nb_philo))
	{
		pthread_mutex_unlock(&p->data->mutex);
		return (1);
	}
	pthread_mutex_unlock(&p->data->mutex);
	return (0);
}

void	philos(t_philo *p)
{
	while (!check_deaths(p))
	{
		start_eating(p);
		my_usleep(p, p->data->time_to_eat);
		finish_eating(p);
		print_msg(p, "is sleeping", 0);
		my_usleep(p, p->data->time_to_sleep);
		print_msg(p, "is thinking", 0);
		usleep(100);
	}
}

void	*routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	p->start = now();
	p->start_eating = now();
	if (p->data->nb_philo == 1)
	{
		printf("%ld %ld has taken a fork\n", now() - p->start, p->index);
		my_usleep(p, p->data->time_to_die);
		printf("%ld %ld died\n", now() - p->start, p->index);
		return (0);
	}
	if (p->index % 2)
	{
		print_msg(p, "is thinking", 0);
		my_usleep(p, p->data->time_to_eat);
	}
	philos(p);
	return (0);
}
