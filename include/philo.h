/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:08:36 by saguesse          #+#    #+#             */
/*   Updated: 2023/02/07 23:49:44 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>

typedef struct s_data
{
	size_t			nb_philo;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			number_eat;
	int				*forks;
	int				*eat_count;
}	t_data;

typedef struct s_philo
{
	int				right;
	int				left;
	size_t			index;
	size_t			start;
	size_t			start_eating;
	t_data			*data;
	pthread_t		t;
	pthread_mutex_t	mutex;
}	t_philo;

int		check_inputs(t_data *data, int argc, char **argv);
int		init(t_philo *p, t_data *data);
int		threads(t_philo *p, t_data *data);
void	*routine(void *data);
void	start_eating(t_philo *p);
void	finish_eating(t_philo *p);
void	thinking(t_philo *p);
void	sleeping(t_philo *p);
int		my_usleep(t_philo *p, int time);
void	clear(t_philo *p, t_data *data);
size_t	now(void);

size_t	ft_atoi(const char *nptr);
size_t	ft_strlen(const char *s);

#endif
