/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:15:11 by jyriarte          #+#    #+#             */
/*   Updated: 2025/02/09 13:38:26 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

int	main(int argc, char **argv)
{
	static t_table	table;
	t_philo			**philosophers;

	if ((argc < 5 || argc > 6) || check_args(argc, argv))
	{
		print_usage();
		return (1);
	}
	if (prepare_table(&table, argc, argv))
	{
		clean_table(&table);
		return (1);
	}
	philosophers = create_philosophers(&table, table.n_of_philos);
	simulate(&table, philosophers);
	free_philosophers(philosophers);
	destroy_mutexes(&table, table.n_of_philos);
	clean_table(&table);
	return (0);
}
