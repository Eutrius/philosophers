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
#include <stdlib.h>
#include <string.h>

static int	create_forks(t_table *table, int size);

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
	if (create_forks(table, table->n_of_philos))
		return (1);
	if (create_mutexes(table, table->n_of_philos))
		return (1);
	if (init_mutexes(table, table->n_of_philos))
		return (1);
	return (0);
}

void	clean_table(t_table *table)
{
	int	i;

	free(table->forks);
	i = 0;
	if (table->mutexes)
	{
		while (i < table->n_of_philos && table->mutexes[i] != NULL)
		{
			free(table->mutexes[i]);
			i++;
		}
		free(table->mutex);
		free(table->mutexes);
	}
}

static int	create_forks(t_table *table, int size)
{
	table->forks = malloc(sizeof(int) * (size));
	if (table->forks == NULL)
		return (1);
	memset(table->forks, 0, sizeof(int) * (size));
	return (0);
}
