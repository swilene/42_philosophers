/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:19:25 by saguesse          #+#    #+#             */
/*   Updated: 2023/02/06 16:03:49 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	*p;

	if (argc < 5 || argc > 6)
		return (printf("Number of arguments must be between 4 and 5.\n"), 1);
	if (check_inputs(&data, argc, argv))
		return (2);
	p = malloc(sizeof(t_philo) * data.nb_philo);
	if (!p)
		return (3);
	init(p, &data);
	threads(p, &data);
	clear(p, &data);
	return (0);
}
