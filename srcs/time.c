/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:01:07 by saguesse          #+#    #+#             */
/*   Updated: 2023/02/10 16:27:35 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long int	now(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000) + (now.tv_usec / 1000));
}

int	my_usleep(t_philo *p, int time)
{
	long long int	t;

	t = now();
	while (now() - t < time)
	{
		if ((int)(now() - p->start_eating) >= p->data->time_to_die)
			print_msg(p, "died", DIED);
		usleep(50);
	}
	return (0);
}
