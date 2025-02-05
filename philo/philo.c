/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:15:11 by jyriarte          #+#    #+#             */
/*   Updated: 2025/02/05 16:41:58 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

t_philo	*create_philosopher(t_table *table, int id, int size);
t_philo	**init_philosophers(t_table *table, int size);
void	free_philosophers(t_philo **philosophers);

int	main(int argc, char **argv)

{
	static t_table table;
	pthread_t thread;
	t_philo **philosophers;

	if (argc < 5 && argc > 6)
	{
		print_usage();
		return (1);
	}
	printf("%li\n", gettimeofday_ms());
	return (0);
}

int	prepare_table(t_table *table, int argc, char **argv)
{
}

t_philo	**init_philosophers(t_table *table, int size)
{
	int		i;
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

t_philo	*create_philosopher(t_table *table, int id, int size)
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
	int	i;

	i = 0;
	while (philosophers[i] != NULL)
	{
		free(philosophers[i]);
		i++;
	}
	free(philosophers);
}
