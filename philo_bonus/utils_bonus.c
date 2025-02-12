/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 22:14:14 by jyriarte          #+#    #+#             */
/*   Updated: 2025/02/12 13:48:48 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <stddef.h>
#include <sys/time.h>
#include <unistd.h>

long	gettimeofday_ms(void)
{
	struct timeval	time;
	static long		start_time;

	gettimeofday(&time, NULL);
	if (start_time == 0)
	{
		start_time = time.tv_sec * 1000 + time.tv_usec / 1000;
		return (0);
	}
	return ((time.tv_sec * 1000 + time.tv_usec / 1000) - start_time);
}

void	custom_sleep(int start, int delay)
{
	while (1)
	{
		if (gettimeofday_ms() - start >= delay)
			break ;
		usleep(100);
	}
}

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (res * 10) + (nptr[i] - '0');
		i++;
	}
	return (res * sign);
}
