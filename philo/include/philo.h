/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:08:36 by saguesse          #+#    #+#             */
/*   Updated: 2023/02/10 10:10:10 by saguesse         ###   ########.fr       */
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

# define EAT 1
# define DIED 2

typedef struct s_data
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_eat;
	int				died;
	int				eat_count;
	pthread_mutex_t	mutex;
}	t_data;

typedef struct s_fork
{
	pthread_mutex_t	mutex_fork;
	int				forks;
}	t_fork;

typedef struct s_philo
{
	int				index;
	int				count;
	long long int	start;
	long long int	start_eating;
	t_data			*data;
	t_fork			*right;
	t_fork			*left;
	pthread_t		t;
}	t_philo;

int				check_inputs(t_data *data, int argc, char **argv);
int				init(t_philo *p, t_data *data, t_fork *forks);
int				threads(t_philo *p, t_data *data);
void			eating(t_philo *p);
void			print_msg(t_philo *p, char *msg, int event);
int				my_usleep(t_philo *p, int time);
void			clear(t_philo *p, t_data *data, t_fork *forks);
long long int	now(void);

#endif
