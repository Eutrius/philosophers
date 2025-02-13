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

/*static int	check_table(t_table *table, t_philo *philo);*/
void	routine(t_table *table, t_philo *philo, sem_t *forks);

void	simulate(t_table *table, t_philo **philosophers)
{
	int	i;

	i = 0;
	gettimeofday_ms();
	while (i < table->n_of_philos)
	{
		philosophers[i]->pid = fork();
		if (philosophers[i]->pid == 0)
			routine(table, philosophers[i], table->forks);
		i++;
	}
	while (1)
	{
		sem_post(philosophers[0]->sem);
		waitpid(-1, NULL, WNOHANG);
	}
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
	exit(0);
}

/*static int	check_table(t_table *table, t_philo *philo)*/
/*{*/
/*	if ((int)(gettimeofday_ms() - philo->last_eaten) >= table->time_to_die)*/
/*	{*/
/*		if (!table->someone_died)*/
/*			pthread_mutex_lock(table->mutex);*/
/*		{*/
/*			table->someone_died = 1;*/
/*			ph_die(philo);*/
/*			pthread_mutex_unlock(table->mutex);*/
/*			return (1);*/
/*		}*/
/*		else pthread_mutex_unlock(table->mutex);*/
/*	}*/
/*	pthread_mutex_lock(table->mutex);*/
/*	if (table->someone_died)*/
/*	{*/
/*		pthread_mutex_unlock(table->mutex);*/
/*		return (1);*/
/*	}*/
/*	pthread_mutex_unlock(table->mutex);*/
/*	return (0);*/
/*}*/
