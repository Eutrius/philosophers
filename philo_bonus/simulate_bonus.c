/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:30:08 by jyriarte          #+#    #+#             */
/*   Updated: 2025/02/13 22:13:40 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <sys/wait.h>
#include <unistd.h>

static void	routine(t_table *table, t_philo *philo, sem_t *forks);

void	simulate(t_table *table, t_philo **philosophers)
{
	int	i;

	i = 0;
	while (i < table->n_of_philos)
	{
		philosophers[i]->pid = fork();
		if (philosophers[i]->pid == 0)
		{
			philosophers[i]->last_eaten = 0;
			routine(table, philosophers[i], table->forks);
		}
		i++;
	}
	monitor(table, philosophers);
}

static void	routine(t_table *table, t_philo *philo, sem_t *forks)

{
	while (1)
	{
		ph_think(philo);
		sem_wait(philo->sem);
		sem_wait(forks);
		ph_take_fork(philo);
		sem_wait(forks);
		ph_take_fork(philo);
		ph_eat(table, philo);
		sem_post(forks);
		sem_post(forks);
		ph_sleep(table, philo);
	}
}
