/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_states_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 09:30:14 by jyriarte          #+#    #+#             */
/*   Updated: 2025/02/13 21:40:23 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <stdio.h>
#include <unistd.h>

void	ph_eat(t_table *table, t_philo *philo)
{
	printf("%li %i is eating\n", gettimeofday_ms(), philo->id);
	custom_sleep(gettimeofday_ms(), table->time_to_eat);
}

void	ph_sleep(t_table *table, t_philo *philo)
{
	printf("%li %i is sleeping\n", gettimeofday_ms(), philo->id);
	custom_sleep(gettimeofday_ms(), table->time_to_sleep);
}

void	ph_think(t_philo *philo)
{
	printf("%li %i is thinking\n", gettimeofday_ms(), philo->id);
}

void	ph_take_fork(t_philo *philo)
{
	printf("%li %i has taken a fork\n", gettimeofday_ms(), philo->id);
}

void	ph_die(int id)
{
	printf("%li %i died\n", gettimeofday_ms(), id);
}
