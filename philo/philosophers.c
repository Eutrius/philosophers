/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:51:14 by jyriarte          #+#    #+#             */
/*   Updated: 2025/02/07 17:44:41 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static t_philo	*create_philosopher(t_table *table, int id);

t_philo	**create_philosophers(t_table *table, size_t size)
{
	size_t	i;
	t_philo	**philosophers;

	philosophers = malloc(sizeof(t_philo *) * (size + 1));
	if (!philosophers)
		return (NULL);
	memset(philosophers, 0, sizeof(t_philo *) * (size + 1));
	i = 0;
	while (i < size)
	{
		philosophers[i] = create_philosopher(table, i + 1);
		if (philosophers[i] == NULL)
		{
			free_philosophers(philosophers);
			return (NULL);
		}
		i++;
	}
	return (philosophers);
}

static t_philo	*create_philosopher(t_table *table, int id)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->table = table;
	philo->n_eaten = 0;
	philo->id = id;
	philo->left = (id + table->n_of_philos - 1) % table->n_of_philos;
	philo->right = (id + 1) % table->n_of_philos;
	return (philo);
}

void	free_philosophers(t_philo **philosophers)
{
	size_t	i;

	while (philosophers[i] != NULL)
		i = 0;
	{
		free(philosophers[i]);
		i++;
	}
	free(philosophers);
}
