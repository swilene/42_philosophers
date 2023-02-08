/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:18:20 by saguesse          #+#    #+#             */
/*   Updated: 2023/02/08 17:17:34 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_msg(t_philo *p, char *s)
{
	pthread_mutex_lock(&p->data->msg);
	if (!p->data->died)
		printf("%lld %ld %s\n", now() - p->start, p->index, s);
	pthread_mutex_unlock(&p->data->msg);
}
