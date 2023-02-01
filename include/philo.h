/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:08:36 by saguesse          #+#    #+#             */
/*   Updated: 2023/02/01 18:28:43 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <pthread.h>

typedef struct s_list
{
	int				nb_philo;
	int				nb_fork;
	struct s_list	*next;
}	t_list;

typedef struct s_data
{
	size_t	nb_philo;
	size_t	die;
	size_t	eat;
	size_t	sleep;
	size_t	number_eat;
	//pthread_t	*p;
	t_list	*lst;
}	t_data;

int		check_inputs(t_data *data, int argc, char **argv);
int		creating_threads(t_data *data);
void	*philo();

size_t	ft_atoi(const char *nptr);
size_t	ft_strlen(const char *s);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int nb);
void	ft_lstclear(t_list **lst);

#endif
