/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:53:34 by saguesse          #+#    #+#             */
/*   Updated: 2023/02/10 16:26:16 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (i);
	while (s[i])
		i++;
	return (i);
}

int	ft_atoi(const char *nptr)
{
	size_t	nb;
	size_t	i;

	nb = 0;
	i = 0;
	if (ft_strlen(nptr) > 10)
		return (2147483648);
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-' && nptr[i + 1] >= '0' && nptr[i + 1] <= '9')
			return (printf("Input can't be negative!\n"), -1);
		i++;
	}
	if (nptr[i] == '\0')
		return (printf("Input must be numeric!\n"), -1);
	while (nptr[i])
	{
		if (nptr[i] < '0' || nptr[i] > '9')
			return (printf("Input must be numeric!\n"), -1);
		nb = nb * 10 + nptr[i] - '0';
		i++;
	}
	if (nb > INT_MAX)
		return (printf("Input must be less than INT_MAX!\n"), -1);
	return ((int)nb);
}

int	check_inputs(t_data *data, int argc, char **argv)
{
	data->nb_philo = ft_atoi(argv[1]);
	if (data->nb_philo == 0)
		return (printf("Number of philisophers must be at least of 1!\n"), 1);
	else if (data->nb_philo < 0)
		return (2);
	data->time_to_die = ft_atoi(argv[2]);
	if (data->time_to_die < 0)
		return (3);
	data->time_to_eat = ft_atoi(argv[3]);
	if (data->time_to_eat < 0)
		return (4);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (data->time_to_sleep < 0)
		return (5);
	if (argc == 6)
	{
		data->number_eat = ft_atoi(argv[5]);
		if (data->number_eat > INT_MAX)
			return (6);
		if (data->number_eat < 1)
			return (printf("Philosophers must eat at least once!\n"), 7);
	}
	else
		data->number_eat = 0;
	return (0);
}
