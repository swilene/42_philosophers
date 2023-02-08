/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:52:13 by saguesse          #+#    #+#             */
/*   Updated: 2023/02/08 17:37:11 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	init_mutex(t_data *data)
{
	pthread_mutex_init(&data->death, NULL);
	pthread_mutex_init(&data->msg, NULL);
	pthread_mutex_init(data->eat_count, NULL);
	pthread_mutex_init(data->forks, NULL);
}

int	init(t_philo *p, t_data *data)
{
	size_t	i;

	data->forks = malloc(sizeof(int) * data->nb_philo);
	if (!data->forks)
		return (printf("forks: Cannot allocate memory.\n"), 1);
	if (data->number_eat)
	{
		data->eat_count = malloc(sizeof(int) * data->nb_philo);
		if (!data->eat_count)
			return (printf("eat_count: Cannot allocate memory.\n"), 1);
		memset(data->eat_count, 0, sizeof(int) * data->nb_philo);
	}
	else
		data->eat_count = NULL;
	data->died = 0;
	i = 0;
	while (i < data->nb_philo)
	{
		p[i].index = i + 1;
		p[i].data = data;
		i++;
	}
	return (0);
}
