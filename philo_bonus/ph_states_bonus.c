/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_states_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 09:30:14 by jyriarte          #+#    #+#             */
/*   Updated: 2025/02/12 13:06:23 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <stdio.h>
#include <unistd.h>

void	ph_eat(int id)
{
	usleep(800 * 1000);
	printf("%li %i is eating\n", gettimeofday_ms(), id);
}

void	ph_sleep(int id)
{
	usleep(200 * 1000);
	printf("%li %i is sleeping\n", gettimeofday_ms(), id);
}

void	ph_think(int id)
{
	printf("%li %i is thinking\n", gettimeofday_ms(), id);
}

void	ph_take_fork(int id)
{
	printf("%li %i has taken a fork\n", gettimeofday_ms(), id);
}
