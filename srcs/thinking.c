/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:16:59 by saguesse          #+#    #+#             */
/*   Updated: 2023/02/03 18:46:48 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	thinking(t_philo *p)
{
	gettimeofday(&p->now, NULL);
	pthread_mutex_lock(&p->mutex);
	printf("%ld %ld is thiking\n\n", (p->now.tv_usec
		- p->data->start.tv_usec) / 1000, p->index);	
	pthread_mutex_unlock(&p->mutex);
}
