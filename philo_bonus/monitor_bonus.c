/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 21:24:43 by jyriarte          #+#    #+#             */
/*   Updated: 2025/02/13 22:59:51 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <stdlib.h>
#include <unistd.h>

static void	check_deaths(t_table *table, t_philo **philosophers);
static void	eat_batch(t_table *table, t_philo **philosophers);

void	monitor(t_table *table, t_philo **philosophers)
{
	int	last_eaten;

	last_eaten = gettimeofday_ms();
	eat_batch(table, philosophers);
	while (1)
	{
		check_deaths(table, philosophers);
		if (gettimeofday_ms() - last_eaten >= table->time_to_eat)
		{
			if (table->n_full == table->n_of_philos)
			{
				kill_all(table, philosophers);
				exit(0);
			}
			last_eaten = gettimeofday_ms();
			eat_batch(table, philosophers);
		}
	}
}

static void	check_deaths(t_table *table, t_philo **philosophers)
{
	int	i;
	int	id;

	i = 0;
	while (i < table->n_of_philos)
	{
		if (((gettimeofday_ms())
				- philosophers[i]->last_eaten) >= table->time_to_die)
		{
			id = i + 1;
			kill_all(table, philosophers);
			ph_die(id);
			exit(0);
		}
		i++;
	}
}

static void	eat_batch(t_table *table, t_philo **philosophers)
{
	static int	id;
	int			i;

	i = 0;
	while (i < table->n_of_philos / 2)
	{
		if (philosophers[id]->slept && gettimeofday_ms()
			- philosophers[id]->last_eaten < table->time_to_eat
			+ table->time_to_sleep)
			break ;
		philosophers[id]->slept = 1;
		philosophers[id]->last_eaten = gettimeofday_ms();
		sem_post(philosophers[id]->sem);
		philosophers[id]->n_eaten++;
		if (philosophers[id]->n_eaten == table->n_to_eat)
			table->n_full++;
		id = (id + 1) % table->n_of_philos;
		i++;
	}
}
