/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:52:13 by saguesse          #+#    #+#             */
/*   Updated: 2023/02/09 16:41:20 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	init_philos(t_philo *p, t_data *data, t_fork *forks)
{
	size_t	i;

	i = 0;
	while (i < data->nb_philo)
	{
		p[i].index = i + 1;
		p[i].count = 0;
		p[i].data = data;
		if (i + 1 == data->nb_philo)
			p[i].right = forks;
		else
			p[i].right = forks + i + 1;
		p[i].left = forks + i;
		i++;
	}
}

int	init(t_philo *p, t_data *data, t_fork *forks)
{
	size_t	i;

	data->died = 0;
	data->eat_count = 0;
	pthread_mutex_init(&data->mutex, NULL);
	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_init(&forks[i].mutex_fork, NULL);
		forks[i].forks = 0;
		i++;
	}
	init_philos(p, data, forks);
	return (0);
}
