/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:24:34 by saguesse          #+#    #+#             */
/*   Updated: 2023/02/02 15:40:56 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_lst(t_data *data)
{
	size_t	i;
	t_list	*new;

	i = 1;
	while (i <= data->nb_philo)
	{
		new = ft_lstnew(i);
		if (!new)
			return (1);
		ft_lstadd_back(&data->lst, new);
		i++;
	}
	return (0);
}

int	philo(t_data *data)
{
	size_t		i;
	pthread_t	p[data->nb_philo];

	if (init_lst(data))
		return (1);
	i = 0;
	while (i < data->nb_philo)
	{
		data->index = i + 1;
		if (pthread_create(p + i, NULL, &routine, data) < 0)
			return (printf("Failed to create thread\n"), 1);
		usleep(50);
		i++;
	}
	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_join(p[i], NULL) < 0)
			return (printf("Failed to join\n"), 2);
		i++;
	}
	return (0);
}
