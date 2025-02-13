/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:15:11 by jyriarte          #+#    #+#             */
/*   Updated: 2025/02/13 12:50:18 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <unistd.h>

int	main(int argc, char **argv)
{
	static t_table	table;
	t_philo			**philosophers;

	if ((argc < 5 || argc > 6) || check_args(argc, argv))
		print_usage();
	if (prepare_table(&table, argc, argv))
		clean_table(&table);
	philosophers = create_philosophers(table.n_of_philos);
	simulate(&table, philosophers);
	return (0);
}
