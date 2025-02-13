/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 22:14:14 by jyriarte          #+#    #+#             */
/*   Updated: 2025/02/13 21:42:45 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

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
	exit(1);
}

long	gettimeofday_ms(void)
{
	struct timeval	time;
	static long		start;

	if (start == 0)
	{
		gettimeofday(&time, NULL);
		start = (time.tv_sec * 1000) + (time.tv_usec / 1000);
		return (0);
	}
	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000) - start);
}

void	custom_sleep(long start, long delay)
{
	while (1)
	{
		if (gettimeofday_ms() - start >= delay)
			break ;
		usleep(100);
	}
}
