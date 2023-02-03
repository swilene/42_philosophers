/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:01:07 by saguesse          #+#    #+#             */
/*   Updated: 2023/02/03 18:41:49 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	my_usleep(t_philo *p, int time)
{
	gettimeofday(&p->now, NULL);
	while (p->now.tv_usec - p->data->start.tv_usec < time * 1000)
	{
		usleep(10);
		gettimeofday(&p->now, NULL);
	}
}
