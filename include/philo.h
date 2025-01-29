/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabastos <gabastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:56:10 by gabastos          #+#    #+#             */
/*   Updated: 2025/01/28 15:18:37 by gabastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>

typedef struct s_philo
{
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*died;
	pthread_mutex_t	*print_mutex;

	int				index;
	int				philo_id;
	int				philo_size;
	int				*died_flag;
	pthread_t		t;

	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			eat_count;
	long			meals_eaten;
	long			last_meal;

	long			timestamp;
	long			current_time;
	struct timeval	time;
}			t_philo;

typedef struct s_data
{
	pthread_mutex_t	*forks;

	t_philo			*philo;
	long			philo_size;

	int				died_flag;
	pthread_mutex_t	died_mutex;
	pthread_mutex_t	print_mutex;
}			t_data;

long	ft_atoi(char *str);
int		validation(char **argv);

#endif