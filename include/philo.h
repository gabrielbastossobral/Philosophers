/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrielsobral <gabrielsobral@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:56:10 by gabastos          #+#    #+#             */
/*   Updated: 2025/01/31 12:34:00 by gabrielsobr      ###   ########.fr       */
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
void	philo_init(int argc, char **argv, t_data *data);
void	create(int argc, char **argv);
void	destroy(t_data *data);
void	execute(t_data *data);
void	*rotine(void *arg);
void	get_forks_and_eat(t_philo *philo);
void	case_one_philo(t_philo *philo);
void	die(t_philo *philo);
void	print_message(char *message, t_philo *philo);
int		ate_all_meals(t_philo *philo);
int		died(t_philo *philo);
int		get_forks(t_philo *philo);
long	get_time(t_philo *philo);
int		precise_sleep(t_philo *philo, long time_to_sleep);

#endif