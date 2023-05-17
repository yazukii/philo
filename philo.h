/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:58:17 by yidouiss          #+#    #+#             */
/*   Updated: 2023/05/08 17:51:15 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int					n_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					need_eat;
	int					go;
	int					meals;
	u_int64_t			start_time;
}	t_philo;

typedef struct s_data
{
	pthread_mutex_t		*death;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	u_int64_t			last_eaten;
	t_philo				*philo;
	int					id;
	int					is_eating;
	int					n_eat;
}	t_data;

u_int64_t	get_time(void);
void		died(u_int64_t time, int id);
int			ft_usleep(useconds_t time);
int			ft_atoi(const char *str);
int			init_philo(t_philo *philo, int argc, char **argv);
void		init_data(t_data *data, t_philo *philo, int id);
void		*routine(void *vdata);
void		*monitor(void *vdata);
int			ft_eat(void *vdata);
int			ft_sleep(void *vdata);
int			ft_think(void *vdata);

#endif