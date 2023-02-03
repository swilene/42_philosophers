/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:35:44 by saguesse          #+#    #+#             */
/*   Updated: 2023/02/03 18:47:01 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	sleeping(t_philo *p)
{
	gettimeofday(&p->now, NULL);
	pthread_mutex_lock(&p->mutex);
	printf("%ld %ld is sleeping\n\n", (p->now.tv_usec
		- p->data->start.tv_usec) / 1000, p->index);	
	pthread_mutex_unlock(&p->mutex);
}