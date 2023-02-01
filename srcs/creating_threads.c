/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_threads.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:24:34 by saguesse          #+#    #+#             */
/*   Updated: 2023/02/01 18:26:58 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	creating_threads(t_data *data)
{
	size_t	i;
	pthread_t	p[data->nb_philo];

	/*t_list	*new;

	while (i <= data->nb_philo)
	{
		new = ft_lstnew(i);
		if (!new)
			return (1);
		ft_lstadd_back(&data->lst, new);
		i++;
	}*/

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_create(p + i, NULL, &philo, NULL) < 0)
			return (printf("Failed to create thread\n"), 1);
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
