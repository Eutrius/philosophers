/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:15:11 by jyriarte          #+#    #+#             */
/*   Updated: 2025/02/07 17:40:42 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <unistd.h>

void	simulate(t_table *table, t_philo **philosophers);
void	ph_sleep(t_table *table, t_philo *philo);
void	ph_think(t_table *table, t_philo *philo);
void	ph_die(t_table *table, t_philo *philo);
void	ph_take_fork(t_table *table, t_philo *philo);
void	ph_eat(t_table *table, t_philo *philo);

int	main(int argc, char **argv)
{
	static t_table	table;
	t_philo			**philosophers;

	if ((argc < 5 || argc > 6) && check_args(argc, argv))
	{
		print_usage();
		return (1);
	}
	if (prepare_table(&table, argc, argv))
	{
		clean_table(&table);
		return (1);
	}
	philosophers = create_philosophers(&table, table.n_of_philos);
	simulate(&table, philosophers);
	free_philosophers(philosophers);
	destroy_mutexes(&table, table.n_of_philos);
	clean_table(&table);
	return (0);
}

void	*routine(void *data)
{
	t_philo	*philo;
	t_table	*table;
	int		id;
	int		left;
	int		right;

	philo = (t_philo *)data;
	table = philo->table;
	id = philo->id;
	philo->last_eaten = gettimeofday_ms();
	left = philo->left;
	right = philo->right;
	while (1)
	{
		if (table->someone_died)
			break ;
		if (id % 2 != 0)
		{
			pthread_mutex_lock(table->mutexes[left]);
			if (table->forks[left] == 0)
			{
				table->forks[left] = 1;
				philo->forks++;
				ph_take_fork(table, philo);
			}
			pthread_mutex_unlock(table->mutexes[left]);
		}
		else
		{
			pthread_mutex_lock(table->mutexes[right]);
			if (table->forks[right] == 0)
			{
				table->forks[right] = 1;
				philo->forks++;
				ph_take_fork(table, philo);
			}
			pthread_mutex_unlock(table->mutexes[right]);
		}
		if (philo->forks == 1 && id % 2 == 0)
		{
			pthread_mutex_lock(table->mutexes[left]);
			if (table->forks[left] == 0)
			{
				table->forks[left] = 1;
				philo->forks++;
				ph_take_fork(table, philo);
			}
			pthread_mutex_unlock(table->mutexes[left]);
		}
		else
		{
			pthread_mutex_lock(table->mutexes[right]);
			if (table->forks[right] == 0)
			{
				table->forks[right] = 1;
				philo->forks++;
				ph_take_fork(table, philo);
			}
			pthread_mutex_unlock(table->mutexes[right]);
		}
		if (philo->forks == 2)
		{
			philo->is_thinking = 0;
			ph_eat(table, philo);
			philo->last_eaten = gettimeofday_ms();
			philo->n_eaten++;
			pthread_mutex_lock(table->mutexes[left]);
			table->forks[left] = 0;
			pthread_mutex_unlock(table->mutexes[left]);
			pthread_mutex_lock(table->mutexes[right]);
			table->forks[right] = 0;
			pthread_mutex_unlock(table->mutexes[right]);
			philo->forks = 0;
			ph_sleep(table, philo);
		}
		if (!philo->is_thinking && philo->forks == 0)
		{
			philo->is_thinking = 1;
			ph_think(table, philo);
		}
		if ((int)(gettimeofday_ms() - philo->last_eaten) >= table->time_to_die)
			ph_die(table, philo);
	}
	return (NULL);
}

void	ph_eat(t_table *table, t_philo *philo)
{
	printf("%li %i is eating", gettimeofday_ms(), philo->id);
	usleep(table->time_to_eat);
}
void	ph_sleep(t_table *table, t_philo *philo)
{
	printf("%li %i is sleeping", gettimeofday_ms(), philo->id);
	usleep(table->time_to_sleep);
}
void	ph_think(t_table *table, t_philo *philo)
{
	(void)table;
	printf("%li %i is thinking", gettimeofday_ms(), philo->id);
}

void	ph_take_fork(t_table *table, t_philo *philo)
{
	(void)table;
	printf("%li %i has taken a fork", gettimeofday_ms(), philo->id);
}
void	ph_die(t_table *table, t_philo *philo)
{
	printf("%li %i died", gettimeofday_ms(), philo->id);
	table->someone_died = 1;
}

void	simulate(t_table *table, t_philo **philosophers)
{
	int	i;
	int	j;

	i = 0;
	while (i < table->n_of_philos)
	{
		if (pthread_create(&philosophers[i]->thread, NULL, routine,
				philosophers[i]))
			break ;
		i++;
	}
	j = 0;
	while (j < i)
	{
		pthread_join(philosophers[j]->thread, NULL);
		j++;
	}
}
