/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:16:47 by saguesse          #+#    #+#             */
/*   Updated: 2023/02/08 17:10:51 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	detroy_mutex(t_data *data)
{
	pthread_mutex_detroy(&data->death, NULL);
	pthread_mutex_detroy(&data->msg, NULL);
	pthread_mutex_detroy(data->eat_count, NULL);
	pthread_mutex_detroy(data->forks, NULL);
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
