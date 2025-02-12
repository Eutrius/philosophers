/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:51:14 by jyriarte          #+#    #+#             */
/*   Updated: 2025/02/12 14:01:30 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*static t_philo	*create_philosopher(t_table *table, int id);*/

/*static t_philo	*create_philosopher(t_table *table, int id)*/
/*{*/
/*	t_philo	*philo;*/
/**/
/*	philo = malloc(sizeof(t_philo));*/
/*	if (!philo)*/
/*		return (NULL);*/
/*	philo->table = table;*/
/*	philo->n_eaten = 0;*/
/*	philo->id = id;*/
/*	if (id % 2 == 0)*/
/*	{*/
/*		philo->left = id - 1;*/
/*		philo->right = id % table->n_of_philos;*/
/*	}*/
/*	else*/
/*	{*/
/*		philo->right = id - 1;*/
/*		philo->left = id % table->n_of_philos;*/
/*	}*/
/*	philo->state = IDLE;*/
/*	philo->forks = 0;*/
/*	philo->sleep = 0;*/
/*	philo->last_eaten = 0;*/
/*	return (philo);*/
/*}*/
/**/
/*void	free_philosophers(t_philo **philosophers)*/
/*{*/
/*	size_t	i;*/
/**/
/*	i = 0;*/
/*	while (philosophers[i] != NULL)*/
/*	{*/
/*		free(philosophers[i]);*/
/*		i++;*/
/*	}*/
/*	free(philosophers);*/
/*}*/
