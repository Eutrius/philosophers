/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:15:11 by jyriarte          #+#    #+#             */
/*   Updated: 2025/02/12 14:39:02 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <fcntl.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void	c_philosophers(int id);

int	main(int argc, char **argv)
{
	t_table	table;
	pid_t	*philosophers;
	int		i;
	int		status;
	int		value;

	if ((argc < 5 || argc > 6) || check_args(argc, argv))
		print_usage();
	prepare_table(&table, argc, argv);
	table.sem = sem_open(TABLE, O_CREAT, 0644, 10);
	if (table.sem == SEM_FAILED)
		printf("FAILED");
	if (sem_getvalue(table.sem, &value) == -1)
	{
		perror("sem_getvalue failed");
	}
	else
	{
		printf("Semaphore value: %d\n", value);
	}
	philosophers = malloc(sizeof(pid_t) * table.n_of_philos);
	i = 0;
	while (i < table.n_of_philos)
	{
		philosophers[i] = fork();
		if (philosophers[i] == -1)
			break ;
		if (philosophers[i] == 0)
		{
			c_philosophers(i + 1);
		}
		i++;
	}
	while (1)
	{
		if (waitpid(philosophers[0], &status, WNOHANG) > 0)
			break ;
		if (waitpid(philosophers[1], &status, WNOHANG) > 0)
			break ;
		usleep(1000);
	}
	free(philosophers);
	return (0);
}

void	c_philosophers(int id)
{
	sem_t	*table;
	int		value;

	table = sem_open(TABLE, 0);
	if (table == SEM_FAILED)
		printf("Hello");
	if (sem_getvalue(table, &value) == -1)
	{
		perror("sem_getvalue failed");
	}
	else
	{
		printf("Semaphore value: %d\n", value);
	}
	while (1)
	{
		ph_think(id);
		sem_wait(table);
		ph_take_fork(id);
		sem_wait(table);
		ph_take_fork(id);
		ph_eat(id);
		sem_post(table);
		sem_post(table);
		ph_sleep(id);
	}
}
