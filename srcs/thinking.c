/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:16:59 by saguesse          #+#    #+#             */
/*   Updated: 2023/02/08 23:44:54 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	thinking(t_philo *p)
{
	pthread_mutex_lock(&p->data->msg);
	print_msg(p, "is thinking");
	pthread_mutex_unlock(&p->data->msg);
}
