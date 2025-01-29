/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabastos <gabastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:55:56 by gabastos          #+#    #+#             */
/*   Updated: 2025/01/28 15:45:41 by gabastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long	ft_atoi(char *str)
{
	long	num;
	int		i;

	i = 0;
	num = 0;
	while (str[i] && ((str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
				|| str[i] == '\r' || str[i] == '\t'
				|| str[i] == '\v' || str[i] == '-')))
		i++;
	while (str[i])
		num = num * 10 + (str[i++] - '0');
	return (num);
}

static int	is_all_number(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!(str[i][j] >= '0' && str[i][j] <= '9'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	is_negative(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i][0] == '-')
			return (1);
		i++;
	}
	return (0);
}

static int	is_zero(char **str)
{
	int	i;

	while (str[i])
	{
		if (ft_atoi(str[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	validation(char **argv)
{
	if (is_all_number(&argv[1]) || is_negative(&argv[1]) || is_zero(&argv[1]))
		return (1);
	return (0);
}
