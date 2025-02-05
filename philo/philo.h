/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:34:27 by jyriarte          #+#    #+#             */
/*   Updated: 2025/02/05 23:36:02 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>

typedef struct s_philo	t_philo;
typedef struct s_table	t_table;

typedef struct s_table
{
	int					*forks;
	int					someone_died;
	int					num_of_philos;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					n_to_eat;
}						t_table;

typedef struct s_philo
{
	pthread_t			thread;
	int					id;
	int					n_eaten;
	int					right;
	int					left;
	t_table				*table;

}						t_philo;

void					print_usage(void);

long					gettimeofday_ms(void);
int						ft_atoi(const char *nptr);

int						check_args(int argc, char **argv);
void					free_philosophers(t_philo **philosophers);
t_philo					**create_philosophers(t_table *table, size_t size);

#endif
