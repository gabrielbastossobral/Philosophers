/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrielsobral <gabrielsobral@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:17:00 by gabrielsobr       #+#    #+#             */
/*   Updated: 2025/01/31 11:29:09 by gabrielsobr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ate_all_meals(t_philo *philo)
{
	return (philo->eat_count == philo->meals_eaten);
}

long	get_time(t_philo *philo)
{
	gettimeofday(&philo->time, NULL);
	return (philo->time.tv_sec * 1000000 + philo->time.tv_usec);
}

void	die(t_philo *philo)
{
	pthread_mutex_lock(philo->died);
	if (*philo->died_flag == 0)
	{
		*philo->died_flag = 1;
		print_message("died", philo);
	}
	pthread_mutex_unlock(philo->died);
}

void	print_message(char *message, t_philo *philo)
{
	philo->current_time = get_time(philo) - philo->timestamp;
	pthread_mutex_lock(philo->print_mutex);
	printf("%ld %d %s\n", philo->current_time / 1000, philo->philo_id, message);
	pthread_mutex_unlock(philo->print_mutex);
}

int	precise_sleep(t_philo *philo, long time_to_sleep)
{
	long	start;

	start = get_time(philo);
	while ((get_time(philo) - start) < time_to_sleep)
	{
		if (died(philo))
			return (1);
		usleep(1000);
	}
	return (0);
}
