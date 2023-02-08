/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:12:20 by saguesse          #+#    #+#             */
/*   Updated: 2023/02/09 00:20:32 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	eating(t_philo *p)
{
	pthread_mutex_lock(&p->data->forks[p->left]);
	print_msg(p, "has taken a fork");
	pthread_mutex_lock(&p->data->forks[p->right]);
	print_msg(p, "has taken a fork");
	print_msg(p, "is eating");
	my_usleep(p, p->data->time_to_eat);
	pthread_mutex_unlock(&p->data->forks[p->left]);
	pthread_mutex_unlock(&p->data->forks[p->right]);
	if (p->data->number_eat)
		p->data->eat_count[p->index - 1]++;
}
