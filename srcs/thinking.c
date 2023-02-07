/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:16:59 by saguesse          #+#    #+#             */
/*   Updated: 2023/02/08 00:09:52 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	thinking(t_philo *p)
{
	size_t	t;

	t = now();
	pthread_mutex_lock(&p->mutex);
	printf("%ld %ld is thiking\n\n", t - p->start, p->index);	
	pthread_mutex_unlock(&p->mutex);
}
