/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:51:14 by jyriarte          #+#    #+#             */
/*   Updated: 2025/02/05 23:10:44 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>
#include <string.h>

static t_philo	*create_philosopher(t_table *table, int id, size_t size);

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
		philosophers[i] = create_philosopher(table, i + 1, size);
		if (philosophers[i] == NULL)
		{
			free_philosophers(philosophers);
			return (NULL);
		}
		i++;
	}
	return (philosophers);
}

static t_philo	*create_philosopher(t_table *table, int id, size_t size)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->table = table;
	philo->n_eaten = 0;
	philo->id = id;
	philo->left = id - 1;
	philo->right = id + 1;
	return (philo);
}

void	free_philosophers(t_philo **philosophers)
{
	size_t	i;

	i = 0;
	while (philosophers[i] != NULL)
	{
		free(philosophers[i]);
		i++;
	}
	free(philosophers);
}
