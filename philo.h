/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:58:17 by yidouiss          #+#    #+#             */
/*   Updated: 2023/04/12 15:55:58 by yidouiss         ###   ########.fr       */
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
	int					n_philo;		//* number of philosophers
	int					time_to_die;	//* time to die in ms
	int					time_to_eat;	//* time to eat in ms
	int					time_to_sleep;	//* time to sleep in ms
	int					need_eat;		//* number of times each philosopher must eat
	u_int64_t			start_time;		//* time when the simulation starts
}	t_philo;

typedef struct s_data
{
	pthread_mutex_t		*left_fork;		//* pointer to the left fork
	pthread_mutex_t		*right_fork;	//* pointer to the right fork
	u_int64_t			last_eaten;		//* time when the philosopher last ate
	t_philo				*philo;			//* links to the philo struct
	int					id;				//* id of the philosopher
	int					dead;			//* 1 if the philosopher is dead
	int					is_eating;		//* 1 if the philosopher is eating
	int					n_eat;			//* number of times the philosopher has eaten
}	t_data;

u_int64_t	get_time(void);																//* returns the time in ms
int			ft_usleep(useconds_t time);													//* sleeps for time ms
int			ft_atoi(const char *str);													//* converts a string to an int
void		init_philo(t_philo *philo, int argc, char **argv);							//* initializes the philo struct
void		init_data(t_data *data, t_philo *philo, int id);	//* initializes the data struct
void		*routine(void *vdata);														//* routine of the philosophers
void		*monitor(void *vdata);														//* monitors the philosophers (exemples: death)
int			ft_eat(void *vdata);														//* eat function
int			ft_sleep(void *vdata);														//* sleep function
int			ft_think(void *vdata);														//* think function

#endif