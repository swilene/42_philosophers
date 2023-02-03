/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:24:34 by saguesse          #+#    #+#             */
/*   Updated: 2023/02/03 17:27:19 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	philo(t_philo *p, t_data *data)
{
	size_t			i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_init(&(p[i].mutex), NULL);
		if (pthread_create(&(p[i].t), NULL, &routine, &p[i]) < 0)
			return (printf("Failed to create thread\n"), 1);
		i++;
	}
	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_join(p[i].t, NULL) < 0)
			return (printf("Failed to join\n"), 2);
		pthread_mutex_destroy(&(p[i].mutex));
		i++;
	}
	return (0);
}
