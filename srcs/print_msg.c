/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:43:33 by saguesse          #+#    #+#             */
/*   Updated: 2023/02/09 16:36:27 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_msg(t_philo *p, char *msg, int event)
{
	pthread_mutex_lock(&p->data->mutex);
	if (!p->data->died)
		printf("%ld %ld %s\n", now() - p->start, p->index, msg);
	if (p->data->number_eat && event == EAT)
	{
		p->count++;
		if (p->data->number_eat && p->count == p->data->number_eat)
			p->data->eat_count++;
	}
	else if (event == DIED)
		p->data->died = 1;
	pthread_mutex_unlock(&p->data->mutex);
}
