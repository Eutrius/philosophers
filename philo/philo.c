/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:15:11 by jyriarte          #+#    #+#             */
/*   Updated: 2025/02/05 23:10:19 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <limits.h>
#include <pthread.h>

int	main(int argc, char **argv)
{
	pthread_t		thread;
	static t_table	table;
	t_philo			**philosophers;

	if (argc < 5 && argc > 6 && !check_args(argc, argv))
	{
		print_usage();
		return (1);
	}
	return (0);
}

void	prepare_table(t_table *table, int argc, char **argv)
{
	table->num_of_philos = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		table->n_to_eat = ft_atoi(argv[5]);
	else
		table->n_to_eat = INT_MAX;
}
