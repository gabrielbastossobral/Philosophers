/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrielsobral <gabrielsobral@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:20:39 by gabrielsobr       #+#    #+#             */
/*   Updated: 2025/01/31 12:34:17 by gabrielsobr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_null(t_data *data)
{
	data->philo = NULL;
	data->philo_size = 0;
}

void	create(int argc, char **argv)
{
	t_data	data;

	set_null(&data);
	if (validation(argv))
		return ;
	philo_init(argc, argv, &data);
	if (!data.philo)
		return (destroy(&data));
	execute(&data);
	destroy(&data);
}

void	execute(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_size)
	{
		if (pthread_create(&data->philo[i].t, NULL,
				&rotine, (void *)&data->philo[i]))
			return ;
		i++;
	}
	i = 0;
	while (i < data->philo_size)
		if (pthread_join(data->philo[i++].t, NULL))
			return ;
	return ;
}

void	destroy(t_data *data)
{
	int	i;

	if (data->philo)
		free(data->philo);
	i = 0;
	while (i < data->philo_size)
		pthread_mutex_destroy(&data->forks[i++]);
	free(data->forks);
	pthread_mutex_destroy(&data->died_mutex);
	pthread_mutex_destroy(&data->print_mutex);
	set_null(data);
	return ;
}
