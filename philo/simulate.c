/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:30:08 by jyriarte          #+#    #+#             */
/*   Updated: 2025/02/09 14:01:24 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

static int	check_table(t_table *table, t_philo *philo);
static void	*routine(void *data);

void	simulate(t_table *table, t_philo **philosophers)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	gettimeofday_ms();
	while (i < table->n_of_philos)
	{
		if (pthread_create(&philosophers[i]->thread, NULL, routine,
				philosophers[i]))
			break ;
		i++;
	}
	while (j < i)
	{
		pthread_join(philosophers[j]->thread, NULL);
		j++;
	}
}

static void	*routine(void *data)
{
	t_philo	*philo;
	t_table	*table;

	philo = (t_philo *)data;
	table = philo->table;
	while (1)
	{
		if (check_table(table, philo))
			break ;
		if (philo->state == IDLE)
			ph_think(table, philo);
		else if (philo->state == THINKING)
		{
			ph_take_fork(table, philo, LEFT);
			if (philo->forks == 1)
				ph_take_fork(table, philo, RIGHT);
			if (philo->forks == 2)
				ph_eat(table, philo);
		}
		else if (philo->state == SLEEPING)
			ph_sleep(table, philo);
	}
	return (NULL);
}

static int	check_table(t_table *table, t_philo *philo)
{
	if ((int)(gettimeofday_ms() - philo->last_eaten) >= table->time_to_die)
	{
		pthread_mutex_lock(table->mutex);
		if (!table->someone_died)
		{
			table->someone_died = 1;
			ph_die(philo);
			pthread_mutex_unlock(table->mutex);
			return (1);
		}
		else
			pthread_mutex_unlock(table->mutex);
	}
	pthread_mutex_lock(table->mutex);
	if (table->someone_died)
	{
		pthread_mutex_unlock(table->mutex);
		return (1);
	}
	pthread_mutex_unlock(table->mutex);
	return (0);
}
