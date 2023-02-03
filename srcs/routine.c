/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:08:41 by saguesse          #+#    #+#             */
/*   Updated: 2023/02/03 18:46:22 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	philo_even(t_philo *p)
{
	thinking(p);
	my_usleep(p, p->data->eat);
	start_eating(p);
	my_usleep(p, p->data->eat);
	finish_eating(p);
}

void	philo_odd(t_philo *p)
{
	start_eating(p);
	my_usleep(p, p->data->eat);
	finish_eating(p);
	sleeping(p);
	my_usleep(p, p->data->sleep);
	thinking(p);
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
	/*while (1)
	{*/
		if (p->index % 2)
			philo_odd(p);
		else
			philo_even(p);

		//eat
		//sleep
		//think
	//}
	return (0);
}
