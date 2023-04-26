/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:39:34 by yidouiss          #+#    #+#             */
/*   Updated: 2023/04/26 17:20:30 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_usleep(useconds_t time)
{
	time_t	start;

	start = get_time();
	while ((get_time() - start) < time)
		usleep(time / 10);
	return (0);
}

u_int64_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (u_int64_t)1000) + (tv.tv_usec / 1000));
}

void	init_philo(t_philo *philo, int argc, char **argv)
{
	philo->n_philo = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo->need_eat = ft_atoi(argv[5]);
	else
		philo->need_eat = -1;
	philo->start_time = get_time();
}

void	init_data(t_data *data, t_philo *philo, int id)
{
	data->id = id;
	data->last_eaten = get_time();
	data->is_eating = 0;
	data->n_eat = 0;
	data->philo = philo;
}
