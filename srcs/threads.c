/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:24:34 by saguesse          #+#    #+#             */
/*   Updated: 2023/02/09 14:07:27 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	threads(t_philo *p, t_data *data)
{
	size_t			i;

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
