/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:35:44 by saguesse          #+#    #+#             */
/*   Updated: 2023/02/09 14:20:52 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	sleeping(t_philo *p)
{
	pthread_mutex_lock(&p->data->mutex);
	printf("%ld %ld is sleeping\n", now() - p->start, p->index);
	pthread_mutex_unlock(&p->data->mutex);
}
