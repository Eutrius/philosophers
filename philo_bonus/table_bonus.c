/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:09:40 by jyriarte          #+#    #+#             */
/*   Updated: 2025/02/13 12:35:56 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <fcntl.h>
#include <semaphore.h>

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
	sem_unlink(FORKS);
	table->forks = sem_open(FORKS, O_CREAT | O_EXCL, 0644, table->n_of_philos);
	if (table->forks == SEM_FAILED)
		return (1);
	return (0);
}

void	clean_table(t_table *table)
{
	if (table->forks && table->forks != SEM_FAILED)
	{
		sem_close(table->forks);
		sem_unlink(FORKS);
	}
}
