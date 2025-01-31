/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrielsobral <gabrielsobral@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:03:06 by gabrielsobr       #+#    #+#             */
/*   Updated: 2025/01/31 12:13:57 by gabrielsobr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	try_to_eat(t_philo *philo)
{
	if (died(philo))
		return ;
	philo->meals_eaten++;
	philo->last_meal = get_time(philo);
	print_message("is eating", philo);
	precise_sleep(philo, philo->time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	get_forks_and_eat(t_philo *philo)
{
	if (ate_all_meals(philo) || died(philo) || get_forks(philo))
		return ;
	try_to_eat(philo);
}

void	case_one_philo(t_philo *philo)
{
	philo->current_time = get_time(philo) - philo->timestamp;
	printf("%ld %d is thinking\n", philo->current_time / 1000, philo->philo_id);
	if (precise_sleep(philo, philo->time_to_die - philo->current_time))
		return ;
}
