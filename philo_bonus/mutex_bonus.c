/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:06:32 by jyriarte          #+#    #+#             */
/*   Updated: 2025/02/12 13:06:13 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <stdlib.h>
#include <string.h>

static pthread_mutex_t	*create_mutex(void);

int	create_mutexes(t_table *table, int size)
{
	int	i;

	table->mutexes = malloc(sizeof(pthread_mutex_t *) * (size));
	if (table->mutexes == NULL)
		return (1);
	memset(table->mutexes, 0, sizeof(pthread_mutex_t *) * (size));
	i = 0;
	while (i < size)
	{
		table->mutexes[i] = create_mutex();
		if (table->mutexes[i] == NULL)
			return (1);
		i++;
	}
	table->mutex = create_mutex();
	if (table->mutex == NULL)
		return (1);
	return (0);
}

int	init_mutexes(t_table *table, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (pthread_mutex_init(table->mutexes[i], NULL))
		{
			destroy_mutexes(table, i);
			return (1);
		}
		i++;
	}
	if (pthread_mutex_init(table->mutex, NULL))
	{
		destroy_mutexes(table, size);
		return (1);
	}
	return (0);
}

void	destroy_mutexes(t_table *table, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (pthread_mutex_destroy(table->mutexes[i]))
			return ;
		i++;
	}
	if (pthread_mutex_destroy(table->mutex))
		return ;
}

static pthread_mutex_t	*create_mutex(void)
{
	pthread_mutex_t	*mutex;

	mutex = malloc(sizeof(pthread_mutex_t));
	if (mutex == NULL)
		return (NULL);
	return (mutex);
}
