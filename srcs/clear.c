/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:16:47 by saguesse          #+#    #+#             */
/*   Updated: 2023/02/08 23:50:16 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	detroy_mutex(t_data *data)
{
	pthread_mutex_destroy(&data->death);
	pthread_mutex_destroy(&data->msg);
	pthread_mutex_destroy(&data->count);
	pthread_mutex_destroy(data->forks);
}

void	clear(t_philo *p, t_data *data)
{
	if (data)
		free(data);
	if (p)
		free(p);
	if (data->forks)
		free(data->forks);
	if (data->eat_count)
		free(data->eat_count);
}
