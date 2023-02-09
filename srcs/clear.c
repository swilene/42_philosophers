/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:16:47 by saguesse          #+#    #+#             */
/*   Updated: 2023/02/09 16:40:26 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	clear(t_philo *p, t_data *data, t_fork *forks)
{
	size_t	i;

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
