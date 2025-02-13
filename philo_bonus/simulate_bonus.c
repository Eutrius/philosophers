/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:30:08 by jyriarte          #+#    #+#             */
/*   Updated: 2025/02/13 12:47:41 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void		routine(t_table *table, t_philo *philo, sem_t *forks);
void		monitor(t_table *table, t_philo **philosophers);
static int	check_death(t_table *table, t_philo *philo);
static void	kill_all(t_table *table, t_philo **philosophers);

void	simulate(t_table *table, t_philo **philosophers)
{
	int	i;

	i = 0;
	table->start_time = gettimeofday_ms();
	while (i < table->n_of_philos)
	{
		philosophers[i]->pid = fork();
		if (philosophers[i]->pid == 0)
		{
			philosophers[i]->last_eaten = gettimeofday_ms() - table->start_time;
			routine(table, philosophers[i], table->forks);
		}
		i++;
	}
	monitor(table, philosophers);
}
void	routine(t_table *table, t_philo *philo, sem_t *forks)

{
	while (1)
	{
		ph_think(table, philo);
		sem_wait(philo->sem);
		sem_wait(forks);
		ph_take_fork(table, philo, LEFT);
		sem_wait(forks);
		ph_take_fork(table, philo, RIGHT);
		ph_eat(table, philo);
		sem_post(forks);
		sem_post(forks);
		ph_sleep(table, philo);
	}
}

void	monitor(t_table *table, t_philo **philosophers)
{
	int	i;
	int	j;

	i = 0;
	while (1)
	{
		j = 0;
		while (j < table->n_of_philos / 2)
		{
			philosophers[(i + j)
				% table->n_of_philos]->last_eaten = gettimeofday_ms()
				- table->start_time;
			sem_post(philosophers[(i + j) % table->n_of_philos]->sem);
			j++;
			j++;
		}
		j = 0;
		while (j < table->n_of_philos)
		{
			if (check_death(table, philosophers[j]))
			{
				ph_die(table, philosophers[j]);
				kill_all(table, philosophers);
			}
			j++;
		}
		i = (i + 1) % table->n_of_philos;
		custom_sleep(gettimeofday_ms(), table->time_to_eat);
	}
}

static int	check_death(t_table *table, t_philo *philo)
{
	if (((gettimeofday_ms() - table->start_time)
			- philo->last_eaten) >= table->time_to_die)
		return (1);
	return (0);
}

static void	kill_all(t_table *table, t_philo **philosophers)
{
	int	i;

	i = 0;
	while (i < table->n_of_philos)
	{
		kill(philosophers[i]->pid, SIGKILL);
		i++;
	}
	free_philosophers(philosophers);
	clean_table(table);
	exit(0);
}
