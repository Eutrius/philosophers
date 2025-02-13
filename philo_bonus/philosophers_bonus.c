/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:51:14 by jyriarte          #+#    #+#             */
/*   Updated: 2025/02/13 12:33:34 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static t_philo	*create_philosopher(int id);

t_philo	**create_philosophers(size_t size)
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
		philosophers[i] = create_philosopher(i + 1);
		if (philosophers[i] == NULL)
		{
			free_philosophers(philosophers);
			return (NULL);
		}
		i++;
	}
	return (philosophers);
}

static t_philo	*create_philosopher(int id)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->n_eaten = 0;
	philo->last_eaten = 0;
	philo->id = id;
	philo->name = ft_strjoin("/philo", ft_itoa(id));
	if (philo->name == NULL)
	{
		free(philo);
		return (NULL);
	}
	sem_unlink(philo->name);
	philo->sem = sem_open(philo->name, O_CREAT | O_EXCL, 0644, 0);
	if (philo->sem == SEM_FAILED)
	{
		free(philo->name);
		free(philo);
		return (NULL);
	}
	return (philo);
}

void	free_philosophers(t_philo **philosophers)
{
	size_t	i;

	i = 0;
	while (philosophers[i] != NULL)
	{
		sem_close(philosophers[i]->sem);
		sem_unlink(philosophers[i]->name);
		free(philosophers[i]->name);
		free(philosophers[i]);
		i++;
	}
	free(philosophers);
}
