/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:16:47 by saguesse          #+#    #+#             */
/*   Updated: 2023/02/06 11:20:56 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	clear(t_philo *p, t_data *data)
{
	if (p)
		free(p);
	if (data->forks)
		free(data->forks);
	if (data->eat_count)
		free(data->eat_count);
}
