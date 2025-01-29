/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabastos <gabastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:23:01 by gabastos          #+#    #+#             */
/*   Updated: 2025/01/29 14:01:11 by gabastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	set_philo(int argc, char **argv, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_size)
	{
		data->philo[i].last_meal = 0;
		data->philo[i].print_mutex = &data->print_mutex;
		data->philo[i].died_flag = &data->died_flag;
		data->philo[i].died = &data->died_mutex;
		data->philo[i].left_fork = &data->forks[i % data->philo_size];
		data->philo[i].right_fork = &data->forks[(i + 1) % data->philo_size];
		data->philo[i].philo_id = i + 1;
		data->philo[i].philo_size = data->philo_size;
		data->philo[i].time_to_die = ft_atoi(argv[2]) * 1000;
		data->philo[i].time_to_eat = ft_atoi(argv[3]) * 1000;
		data->philo[i].time_to_sleep = ft_atoi(argv[4]) * 1000;
		data->philo[i].meals_eaten = 0;
		data->philo[i].index = i;
		data->philo[i].timestamp = get_time(&data->philo[i]);
		data->philo[i].current_time = 0;
		if (argc == 6)
			data->philo[i++].eat_count = ft_atoi(argv[5]);
		else
			data->philo[i++].eat_count = -1;
	}
}

void	philo_stack(int argc, char **argv, t_data *data)
{
	long	i;

	data->philo_size = ft_atoi(argv[1]);
	data->philo = malloc(sizeof(t_philo) * data->philo_size);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_size);
	if (!data->philo || !data->forks)
		return ;
	i = 0;
	while (i < data->philo_size)
		pthread_mutex_init(&data->forks[i++], NULL);
	pthread_mutex_init(&data->died_mutex, NULL);
	pthread_mutex_init(&data->print_mutex, NULL);
	data->died_flag = 0;
	set_philo(argc, argv, data);
}
