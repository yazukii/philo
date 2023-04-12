/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:17:39 by yidouiss          #+#    #+#             */
/*   Updated: 2023/04/12 16:04:37 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int argc, char **argv)
{
	t_philo			philo;
	t_data			data[ft_atoi(argv[1])];
	pthread_t		philos[ft_atoi(argv[1])];
	pthread_t		monitoring;
	pthread_mutex_t	forks[ft_atoi(argv[1])];
	int				i;

	i = 0;
	init_philo(&philo, argc, argv);
	while (i < philo.n_philo)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	i = 0;
	while(i < philo.n_philo)
	{
		init_data(&data[i], &philo, i);
		data->left_fork = &forks[i];
		if (i == 0)
			data->right_fork = &forks[philo.n_philo - 1];
		else
			data->right_fork = &forks[i - 1];
		i++;
	}
	i = 0;
	philo.start_time = get_time();
	pthread_create(&monitoring, NULL, &monitor, &data);
	while (i < philo.n_philo)
	{
		pthread_create(&philos[i], NULL, &routine, &data[i]);
		i++;
	}
	i = 0;
	while (i < philo.n_philo)
	{
		pthread_join(philos[i], NULL);
		i++;
	}
	pthread_join(monitoring, NULL);
	return (0);
}
