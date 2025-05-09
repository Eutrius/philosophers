/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 22:14:14 by jyriarte          #+#    #+#             */
/*   Updated: 2025/02/09 09:42:50 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stddef.h>
#include <stdio.h>
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

void	print_usage(void)
{
	printf("Usage:\n\n./philo nphilosophers time_to_die ");
	printf("time_to_eat time_to_sleep ");
	printf("[ntimes_must_eat]\n");
	printf("\nArguments:\n\n");
	printf("  nphilosophers      : Positive Integer\n\n");
	printf("               The number of philosophers. Must be a");
	printf(" positive integer.\n\n");
	printf("  time_to_die                 : Positive Integer\n\n");
	printf("               Time in milliseconds before a philosopher");
	printf(" dies if not eating.\n\n");
	printf("  time_to_eat                 : Positive Integer\n\n");
	printf("               Time in milliseconds for a philosopher to");
	printf(" eat.\n\n");
	printf("  time_to_sleep               : Positive Integer\n\n");
	printf("               Time in milliseconds for a philosopher to");
	printf(" sleep.\n\n");
	printf("  [ntimes_must_eat]");
	printf(" : Positive Integer (optional)\n\n");
	printf("               The number of times each philosopher");
	printf(" must eat. If not provided, there is no limit.\n\n");
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
