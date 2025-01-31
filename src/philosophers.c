/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrielsobral <gabrielsobral@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:02:59 by gabrielsobr       #+#    #+#             */
/*   Updated: 2025/01/31 12:31:29 by gabrielsobr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	try_to_sleep(t_philo *philo)
{
	precise_sleep(philo, 1000);
	if (ate_all_meals(philo) || died(philo))
		return ;
	print_message("is sleeping", philo);
	precise_sleep(philo, philo->time_to_sleep);
}

static void	try_to_get_forks(t_philo *philo)
{
	if (!died(philo))
		print_message("is thinking", philo);
	if (precise_sleep(philo, 1000))
		return ;
	get_forks_and_eat(philo);
	try_to_sleep(philo);
}

int	died(t_philo *philo)
{
	pthread_mutex_lock(philo->died);
	if (*philo->died_flag)
	{
		pthread_mutex_unlock(philo->died);
		return (1);
	}
	pthread_mutex_unlock(philo->died);
	if (philo->last_meal == 0)
	{
		if (get_time(philo) - philo->timestamp >= philo->time_to_die)
		{
			die(philo);
			return (1);
		}
	}
	else if (get_time(philo) - philo->last_meal >= philo->time_to_die)
	{
		die(philo);
		return (1);
	}
	return (0);
}

void	*rotine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (ate_all_meals(philo) || died(philo))
			break ;
		if (philo->philo_size == 1)
			case_one_philo(philo);
		else
			try_to_get_forks(philo);
	}
	return (NULL);
}
