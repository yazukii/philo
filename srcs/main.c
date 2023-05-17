/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:17:39 by yidouiss          #+#    #+#             */
/*   Updated: 2023/05/08 17:00:44 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int argc, char **argv)
{
	t_philo			philo;
	t_data			*data;
	pthread_mutex_t	*forks;
	pthread_mutex_t	death;
	pthread_t		*philos;
	pthread_t		*monitoring;
	int				i;

	i = 0;
	if (argc < 5 || argc > 6)
		return (printf("Error: wrong number of arguments\n"));
	data = malloc(sizeof(t_data) * ft_atoi(argv[1]));
	philos = malloc(sizeof(pthread_mutex_t) * ft_atoi(argv[1]));
	monitoring = malloc(sizeof(pthread_mutex_t) * ft_atoi(argv[1]));
	forks = malloc(sizeof(pthread_t) * ft_atoi(argv[1]));
	if (init_philo(&philo, argc, argv) == 1)
		return (printf("Error: wrong arguments\n"));
	pthread_mutex_init(&death, NULL);
	while (i < philo.n_philo)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	i = 0;
	while (i < philo.n_philo)
	{
		init_data(&data[i], &philo, i);
		data[i].left_fork = &forks[i];
		data[i].death = &death;
		if (i == 0)
			data[i].right_fork = &forks[philo.n_philo - 1];
		else
			data[i].right_fork = &forks[i - 1];
		i++;
	}
	i = 0;
	while (i < philo.n_philo)
	{
		pthread_create(&monitoring[i], NULL, &monitor, &data[i]);
		pthread_create(&philos[i], NULL, &routine, &data[i]);
		i++;
	}
	philo.start_time = get_time();
	philo.go = 1;
	i = 0;
	while (i < philo.n_philo)
	{
		pthread_join(philos[i], NULL);
		pthread_join(monitoring[i], NULL);
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	pthread_mutex_destroy(&death);
	free(data);
	free(philos);
	free(forks);
	return (0);
}
