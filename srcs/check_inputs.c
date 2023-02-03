/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:53:34 by saguesse          #+#    #+#             */
/*   Updated: 2023/02/03 12:21:02 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_inputs(t_data *data, int argc, char **argv)
{
	data->nb_philo = ft_atoi(argv[1]);
	if (data->nb_philo < 1)
		return (printf("Number of philisophers must be at least of 1!\n"), 1);
	data->die = ft_atoi(argv[2]);
	data->eat = ft_atoi(argv[3]);
	data->sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->number_eat = ft_atoi(argv[5]);
	else
		data->number_eat = 0;
	if (data->nb_philo > INT_MAX || data->die > INT_MAX || data->eat > INT_MAX
		|| data->sleep > INT_MAX)
		return (2);
	if (data->number_eat && data->number_eat > INT_MAX)
		return (3);
	return (0);
}
