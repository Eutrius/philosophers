/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:34:27 by jyriarte          #+#    #+#             */
/*   Updated: 2025/02/09 13:31:30 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>

# define LEFT 0
# define RIGHT 1

typedef struct s_philo	t_philo;
typedef struct s_table	t_table;

typedef struct s_table
{
	pthread_mutex_t		**mutexes;
	pthread_mutex_t		*mutex;
	int					*forks;
	int					someone_died;
	int					n_of_philos;
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
	long				last_eaten;
	int					forks;
	int					is_thinking;
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
void					simulate(t_table *table, t_philo **philosophers);

void					ph_sleep(t_table *table, t_philo *philo);
void					ph_think(t_table *table, t_philo *philo);
void					ph_die(t_philo *philo);
void					ph_take_fork(t_table *table, t_philo *philo, int right);
void					ph_eat(t_table *table, t_philo *philo);

int						prepare_table(t_table *table, int argc, char **argv);
void					clean_table(t_table *table);
int						create_mutexes(t_table *table, int size);
int						init_mutexes(t_table *table, int size);
void					destroy_mutexes(t_table *table, int size);

#endif
