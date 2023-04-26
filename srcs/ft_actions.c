/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:00:19 by yidouiss          #+#    #+#             */
/*   Updated: 2023/04/26 16:27:30 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_sleep(void *vdata)
{
	time_t		strt;
	t_data		*data;

	data = (t_data *)vdata;
	strt = data->philo->start_time;
	printf("%llu %d is sleeping\n", get_time() - strt, data->id + 1);
	ft_usleep(data->philo->time_to_sleep);
	return (0);
}

int	ft_eat(void *vdata)
{
	time_t	strt;
	t_data	*data;

	data = (t_data *)vdata;
	strt = data->philo->start_time;
	pthread_mutex_lock(data->left_fork);
	printf("%llu %d has taken a fork\n", get_time() - strt, data->id + 1);
	pthread_mutex_lock(data->right_fork);
	printf("%llu %d has taken a fork\n", get_time() - strt, data->id + 1);
	data->is_eating = 1;
	printf("%llu %d is eating\n", get_time() - strt, data->id + 1);
	ft_usleep(data->philo->time_to_eat);
	data->last_eaten = get_time();
	data->n_eat++;
	pthread_mutex_unlock(data->left_fork);
	pthread_mutex_unlock(data->right_fork);
	data->is_eating = 0;
	return (0);
}

int	ft_think(void *vdata)
{
	time_t	strt;
	t_data	*data;

	data = (t_data *)vdata;
	strt = data->philo->start_time;
	printf("%llu %d is thinking\n", get_time() - strt, data->id + 1);
	return (0);
}
