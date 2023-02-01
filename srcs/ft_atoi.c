/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:41:55 by saguesse          #+#    #+#             */
/*   Updated: 2023/02/01 15:31:04 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

size_t	ft_atoi(const char *nptr)
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
			return (printf("Input can't be negative!\n"), 2147483648);
		i++;
	}
	if (nptr[i] == '\0')
		return (printf("Input must be numeric!\n"), 2147483648);
	while (nptr[i])
	{
		if (nptr[i] < '0' || nptr[i] > '9')
			return (printf("Input must be numeric!\n"), 2147483648);
		nb = nb * 10 + nptr[i] - '0';
		i++;
	}
	if (nb > INT_MAX)
		return (printf("Input must be less than INT_MAX!\n"), 2147483648);
	return (nb);
}
