/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:07:37 by yidouiss          #+#    #+#             */
/*   Updated: 2023/05/08 17:51:07 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*monitor(void *vdata)
{
	t_data		*data;
	u_int64_t	leat;
	u_int64_t	ttd;

	data = (t_data *)vdata;
	while (1)
	{
		pthread_mutex_lock(data->death);
		leat = data->last_eaten;
		ttd = (u_int64_t)data->philo->time_to_die;
		if (get_time() - leat > ttd && data->is_eating == 0)
			died(get_time() - data->philo->start_time, data->id);
		pthread_mutex_unlock(data->death);
	}
	return (NULL);
}

void	*routine(void *vdata)
{
	time_t	strt;
	t_data	*data;
	data = (t_data *)vdata;
	while (data->philo->go == 0)
		usleep(1);
	if (data->id % 2 == 0)
	{
		strt = data->philo->start_time;
		printf("%llu %d is thinking\n", get_time() - strt, data->id + 1);
		ft_usleep(data->philo->time_to_sleep);
	}
	while (1)
	{
		ft_eat(data);
		ft_sleep(data);
		ft_think(data);
	}
	return (NULL);
}
