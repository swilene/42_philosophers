/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:19:25 by saguesse          #+#    #+#             */
/*   Updated: 2023/02/10 16:26:53 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clear(t_philo *p, t_data *data, t_fork *forks)
{
	int	i;

	i = 0;
	if (forks)
	{
		while (i < data->nb_philo)
		{
			pthread_mutex_destroy(&forks[i].mutex_fork);
			i++;
		}
		free(forks);
	}
	pthread_mutex_destroy(&data->mutex);
	if (data)
		free(data);
	if (p)
		free(p);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_philo	*p;
	t_fork	*forks;

	if (argc < 5 || argc > 6)
		return (printf("Number of arguments must be between 4 and 5.\n"), 1);
	data = malloc(sizeof(t_data));
	if (!data)
		return (2);
	if (check_inputs(data, argc, argv))
		return (free(data), 2);
	p = malloc(sizeof(t_philo) * data->nb_philo);
	if (!p)
		return (free(data), 3);
	forks = malloc(sizeof(t_fork) * data->nb_philo);
	if (!forks)
	{
		free(data);
		return (free(p), 4);
	}
	init(p, data, forks);
	threads(p, data);
	clear(p, data, forks);
	return (0);
}
