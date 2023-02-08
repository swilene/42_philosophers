/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:35:44 by saguesse          #+#    #+#             */
/*   Updated: 2023/02/08 14:27:59 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	sleeping(t_philo *p)
{
	size_t	t;

	t = now();
	pthread_mutex_lock(&p->mutex);
	if (!p->data->death)
		printf("%ld %ld is sleeping\n", t - p->start, p->index);
	pthread_mutex_unlock(&p->mutex);
}
