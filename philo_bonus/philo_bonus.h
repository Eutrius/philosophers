/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:34:27 by jyriarte          #+#    #+#             */
/*   Updated: 2025/02/13 12:14:52 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <pthread.h>
# include <semaphore.h>

# define LEFT 0
# define RIGHT 1
# define FORKS "/forks"

typedef struct s_philo	t_philo;
typedef struct s_table	t_table;
typedef enum e_state	t_state;

typedef struct s_table
{
	sem_t				*forks;
	int					someone_died;
	int					n_of_philos;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					n_to_eat;
	int					n_full;
}						t_table;

typedef struct s_philo
{
	pid_t				pid;
	int					id;
	int					n_eaten;
	long				last_eaten;
	char				*name;
	sem_t				*sem;

}						t_philo;

typedef enum e_state
{
	IDLE,
	THINKING,
	SLEEPING,
}						t_state;

void					print_usage(void);
long					gettimeofday_ms(void);
void					custom_sleep(int start, int delay);

int						ft_atoi(const char *nptr);
char					*ft_itoa(int n);
char					*ft_strjoin(char const *s1, char *s2);
size_t					ft_strlen(const char *str);

int						check_args(int argc, char **argv);
void					free_philosophers(t_philo **philosophers);
t_philo					**create_philosophers(size_t size);
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
