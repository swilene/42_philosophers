/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 09:51:29 by saguesse          #+#    #+#             */
/*   Updated: 2023/02/01 17:49:18 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_list	*ft_lstnew(int nb)
{
	t_list	*head;

	head = malloc(sizeof(t_list));
	if (!head)
		return (printf("new: Cannot allocate memory.\n"), NULL);
	head->nb_philo = nb;
	head->nb_fork = nb;
	head->next = NULL;
	return (head);
}
