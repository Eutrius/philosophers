/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_usage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:35:11 by jyriarte          #+#    #+#             */
/*   Updated: 2025/02/09 13:45:47 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

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
