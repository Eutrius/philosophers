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

int	main(int argc, char **argv)
{
	pid_t	*philosophers;
	int		n_philos;
	int		i;
	int		j;

	if ((argc < 5 || argc > 6) || check_args(argc, argv))
		print_usage();
	n_philos = ft_atoi(argv[1]);
	philosophers = malloc(sizeof(pid_t) * n_philos);
	i = 0;
	j = 0;
	while (i < n_philos)
	{
		philosophers[i] = fork();
		if (philosophers[i] == -1)
			break ;
		if (philosophers[i] == 0)
		{
			printf("%i\n", i);
			exit(0);
		}
		i++;
	}
	while (j < i)
	{
		waitpid(philosophers[j], NULL, WNOHANG);
		j++;
	}
	free(philosophers);
	return (0);
}
