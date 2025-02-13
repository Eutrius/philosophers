/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_states_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 09:30:14 by jyriarte          #+#    #+#             */
/*   Updated: 2025/02/13 12:24:37 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <stdio.h>
#include <unistd.h>

void	ph_eat(t_table *table, t_philo *philo)
{
	printf("%li %i is eating\n", gettimeofday_ms() - table->start_time,
		philo->id);
	custom_sleep(gettimeofday_ms(), table->time_to_eat);
	/*philo->n_eaten++;*/
	/*if (philo->n_eaten == table->n_to_eat)*/
	/*{*/
	/*	pthread_mutex_lock(table->mutex);*/
	/*	table->n_full++;*/
	/*	if (table->n_full == table->n_of_philos)*/
	/*		table->someone_died = 1;*/
	/*	pthread_mutex_unlock(table->mutex);*/
	/*}*/
	/*pthread_mutex_lock(table->mutexes[philo->left]);*/
	/*table->forks[philo->left] = philo->id;*/
	/*pthread_mutex_unlock(table->mutexes[philo->left]);*/
	/*pthread_mutex_lock(table->mutexes[philo->right]);*/
	/*table->forks[philo->right] = philo->id;*/
	/*pthread_mutex_unlock(table->mutexes[philo->right]);*/
	/*philo->forks = 0;*/
	/*philo->sleep = -1;*/
	/*philo->state = SLEEPING;*/
}

void	ph_sleep(t_table *table, t_philo *philo)
{
	printf("%li %i is sleeping\n", gettimeofday_ms() - table->start_time,
		philo->id);
	custom_sleep(gettimeofday_ms(), table->time_to_sleep);
	/*custom_sleep(gettimeofday_ms(), table->time_to_sleep);*/
	/*if (philo->sleep == -1)*/
	/*{*/
	/*	philo->sleep = gettimeofday_ms();*/
	/*	pthread_mutex_lock(table->mutex);*/
	/*	if (!table->someone_died)*/
	/*		printf("%li %i is sleeping\n", gettimeofday_ms(), philo->id);*/
	/*	pthread_mutex_unlock(table->mutex);*/
	/*}*/
	/*else if (gettimeofday_ms() - philo->sleep >= table->time_to_sleep)*/
	/*{*/
	/*	philo->sleep = 0;*/
	/*	philo->state = IDLE;*/
	/*}*/
}

void	ph_think(t_table *table, t_philo *philo)
{
	(void)table;
	printf("%li %i is thinking\n", gettimeofday_ms() - table->start_time,
		philo->id);
}

void	ph_take_fork(t_table *table, t_philo *philo, int right)
{
	printf("%li %i has taken a fork\n", gettimeofday_ms() - table->start_time,
		philo->id);
	/*int	hand;*/
	/**/
	/*hand = philo->left;*/
	/*if (right)*/
	/*	hand = philo->right;*/
	/*pthread_mutex_lock(table->mutexes[hand]);*/
	/*if (table->forks[hand] != -1 && table->forks[hand] != philo->id)*/
	/*{*/
	/*	table->forks[hand] = -1;*/
	/*	pthread_mutex_unlock(table->mutexes[hand]);*/
	/*	philo->forks++;*/
	/*	pthread_mutex_lock(table->mutex);*/
	/*	if (!table->someone_died)*/
	/*		printf("%li %i has taken a fork\n", gettimeofday_ms(), philo->id);*/
	/*	pthread_mutex_unlock(table->mutex);*/
	/*}*/
	/*else*/
	/*	pthread_mutex_unlock(table->mutexes[hand]);*/
}

void	ph_die(t_table *table, t_philo *philo)
{
	printf("%li %i died\n", gettimeofday_ms() - table->start_time, philo->id);
}
