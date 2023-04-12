/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:07:37 by yidouiss          #+#    #+#             */
/*   Updated: 2023/04/12 16:03:42 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*monitor(void *vdata)
{
	t_data		*data;
	int			i;

	data = (t_data *)vdata;
	i = 0;
	while (1)
	{
		while(i < data->philo->n_philo)
		{
			if (get_time() - data[i].last_eaten > (u_int64_t)data[i].philo->time_to_die && data[i].last_eaten != 0 && data[i].is_eating == 0)
			{
				printf("%llu %d died\n", get_time() - data->philo->start_time, data->id);
				data[i].dead = 1;
				exit(0);
			}
			i++;
		}
		i = 0;
	}
	return (NULL);
}

void	*routine(void *vdata)
{
	t_data	*data;

	data = (t_data *)vdata;
	if (data->id % 2 == 0)
		ft_sleep(data);
	while (data->dead == 0)
	{
		ft_eat(data);
		ft_sleep(data);
		ft_think(data);
	}
	return (NULL);
}