/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 22:06:52 by jyriarte          #+#    #+#             */
/*   Updated: 2025/02/05 22:18:31 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <limits.h>

static int	validate_arg(char *arg);

int	check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!validate_arg(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	validate_arg(char *arg)
{
	int		i;
	long	num;

	i = 0;
	num = 0;
	if (arg[i] == '-' || arg[i] == '+')
	{
		if (arg[i] == '-')
			return (0);
		i++;
	}
	while (arg[i] != '\0')
	{
		if (arg[i] < '0' && arg[i] > '9')
			return (0);
		num = (num * 10) + (arg[i] - '0');
		if (num > INT_MAX)
			return (0);
	}
	return (num != 0);
}
