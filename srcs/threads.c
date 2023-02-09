/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:24:34 by saguesse          #+#    #+#             */
/*   Updated: 2023/02/09 22:37:00 by saguesse         ###   ########.fr       */
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

void	*routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	p->start = now();
	p->start_eating = now();
	if (p->data->nb_philo == 1)
	{
		usleep(p->data->time_to_die * 1000);
		printf("%lld %d died\n", now() - p->start, p->index);
		return (0);
	}
	if (p->index % 2)
	{
		print_msg(p, "is thinking", 0);
		my_usleep(p, p->data->time_to_eat);
	}
	while (!check_deaths(p))
	{
		eating(p);
		print_msg(p, "is sleeping", 0);
		my_usleep(p, p->data->time_to_sleep);
		print_msg(p, "is thinking", 0);
		usleep(100);
	}
	return (0);
}

int	threads(t_philo *p, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_create(&(p[i].t), NULL, &routine, &p[i]) < 0)
			return (printf("Failed to create thread\n"), 1);
		i++;
	}
	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_join(p[i].t, NULL) < 0)
			return (printf("Failed to join\n"), 2);
		i++;
	}
	return (0);
}
