/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:05:39 by jyriarte          #+#    #+#             */
/*   Updated: 2025/02/12 14:30:04 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <pthread.h>
# include <semaphore.h>

# define TABLE "/table"

typedef struct s_philo	t_philo;
typedef struct s_table	t_table;
typedef enum e_state	t_state;

typedef struct s_table
{
	int					n_of_philos;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					n_to_eat;
	int					n_full;
	sem_t				*sem;
}						t_table;

typedef struct s_philo
{
	pthread_t			thread;
	int					id;
	int					n_eaten;
	long				last_eaten;
	long				sleep;
	int					forks;
	int					right;
	int					left;
	t_table				*table;
	int					state;

}						t_philo;

typedef enum e_state
{
	IDLE,
	THINKING,
	SLEEPING,
}						t_state;

void					print_usage(void);

long					gettimeofday_ms(void);
int						ft_atoi(const char *nptr);
void					custom_sleep(int start, int delay);

int						check_args(int argc, char **argv);
void					free_philosophers(t_philo **philosophers);
void					simulate(t_table *table, t_philo **philosophers);

void					ph_sleep(int id);
void					ph_think(int id);
void					ph_take_fork(int id);
void					ph_eat(int id);

int						prepare_table(t_table *table, int argc, char **argv);
void					clean_table(t_table *table);
int						create_mutexes(t_table *table, int size);
int						init_mutexes(t_table *table, int size);
void					destroy_mutexes(t_table *table, int size);

#endif
