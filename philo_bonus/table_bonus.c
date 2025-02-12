/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:09:40 by jyriarte          #+#    #+#             */
/*   Updated: 2025/02/12 13:06:52 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <fcntl.h>
#include <semaphore.h>
#include <unistd.h>

int	prepare_table(t_table *table, int argc, char **argv)
{
	table->n_of_philos = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	table->n_full = 0;
	if (argc == 6)
		table->n_to_eat = ft_atoi(argv[5]);
	else
		table->n_to_eat = -1;
	usleep(1000);
	return (0);
}
