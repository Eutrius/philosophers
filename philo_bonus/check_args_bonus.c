/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 22:06:52 by jyriarte          #+#    #+#             */
/*   Updated: 2025/02/12 13:05:53 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <limits.h>

static int	validate_arg(char *arg, int index);

int	check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (validate_arg(argv[i], i))
			return (1);
		i++;
	}
	return (0);
}

static int	validate_arg(char *arg, int index)
{
	int		i;
	long	num;

	i = 0;
	num = 0;
	if (arg[i] == '-' || arg[i] == '+')
	{
		if (arg[i] == '-')
			return (1);
		i++;
	}
	while (arg[i] != '\0')
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (1);
		num = (num * 10) + (arg[i] - '0');
		if (num > INT_MAX)
			return (1);
		i++;
	}
	if (num == 0 && index != 5)
		return (1);
	return (0);
}
