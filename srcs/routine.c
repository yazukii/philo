/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:07:37 by yidouiss          #+#    #+#             */
/*   Updated: 2023/04/26 18:19:56 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*num_eaten(void *vdata)
{
	t_data	*data;
	int		i;

	i = 0;
	data = (t_data *)vdata;
	printf("n_philo = %d\n", data[1].philo->n_philo);
	while (i < data[1].philo->n_philo)
	{
		i++;
		//printf("i = %d\n", i);
	}
	return (NULL);
}

void	*monitor(void *vdata)
{
	t_data		*data;
	int			i;
	u_int64_t	leat;
	u_int64_t	ttd;

	data = (t_data *)vdata;
	i = 0;
	while (1)
	{
		leat = data->last_eaten;
		ttd = (u_int64_t)data->philo->time_to_die;
		if (get_time() - leat > ttd && data->is_eating == 0)
		{
			printf("%llu %d died\n", get_time() - data->philo->start_time, data->id + 1);
			exit(0);
		}
		i++;
		//num_eaten(data);
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
	while (1)
	{
		ft_eat(data);
		ft_sleep(data);
		ft_think(data);
	}
	return (NULL);
}
