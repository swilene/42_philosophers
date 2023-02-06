/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:08:41 by saguesse          #+#    #+#             */
/*   Updated: 2023/02/06 18:02:48 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	philo(t_philo *p)
{
	start_eating(p);
	if (my_usleep(p, p->data->time_to_eat))
		return (1);
	finish_eating(p);
	sleeping(p);
	if (my_usleep(p, p->data->time_to_sleep))
		return (2);
	thinking(p);
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	if (p->index == p->data->nb_philo)
		p->right = 0;
	else
		p->right = p->index;
	p->left = p->index - 1;
	gettimeofday(&p->start, NULL);
	gettimeofday(&p->start_eating, NULL);
	if (p->index % 2)
	{
		thinking(p);
		my_usleep(p, p->data->time_to_eat);
	}
	//philo(p);
	while (1)
	{
		if (philo(p))
			break;
	}
	return (0);
}
