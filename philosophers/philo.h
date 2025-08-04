/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:07:49 by jougarte          #+#    #+#             */
/*   Updated: 2025/08/04 17:12:32 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/time.h>
#include <limits.h>
#include <errno.h>

#define DEBUG_MODE 0
//structs
//mutex used to block access of the fork (only one at a time)
typedef pthread_mutex_t	t_mtx;
typedef struct s_table	t_table;
typedef struct s_fork	t_fork;
//Enum is to make like a multioption, i use it for a handle function
typedef enum e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}	t_opcode;
//codes for get time
typedef enum e_time_code
{
	SECOND,
	MILISECOND,
	MICROSECOND,
}	t_time_code;

typedef enum e_status
{
	EATING,
	SLEEPING,
	THINKING,
	TAKE_FIRST_FORK,
	TAKE_SECOND_FORK,
	DIED,
}	t_philo_state;

typedef struct s_philo
{
	int			id;
	long		nbr_meals;
	bool		full;
	long		last_time_meal;
	t_fork		*fork1;
	t_fork		*fork2;
	pthread_t	thread_id;
	t_mtx		philo_mutex;
	t_table		*table;
}	t_philo;

struct s_fork
{
	t_mtx	fork;
	int		id;
};

struct s_table
{
	long		philo_nbr;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long		nbr_limit_meals;
	long		start_simulation_time;
	bool		end_simulation;
	bool		threads_ready;
	pthread_t	monitor;
	long		threads_running_nbr;
	t_mtx		table_mutex;
	t_mtx		write_mutex;
	t_fork		*forks;
	t_philo		*philos;
};
//functions
//utils
void	ft_error(char *error);
long	ft_atol(const char *str);
long	gettime(t_time_code time_code);
void	ft_usleep(long usec, t_table *table);
void	clean_data(t_table *table);
//parsing
void	parse_input(t_table *table, char **av, int ac);
//safe functions
void	*safe_malloc(size_t bytes);
void	safe_mutex_handle(t_mtx *mutex, t_opcode opcode);
void	safe_thread_handle(pthread_t *thread, void *(*foo)(void *),
			void *data, t_opcode opcode);
//init
void	data_init(t_table *table);
//simulation
void	init_simulation(t_table *table);
void	*dinner_simulation(void *data);
void	write_status(t_philo_state status, t_philo *philo, bool debug);
void	*lonely(void *arg);
void	think(t_philo *philo, bool b);
//getters/setters
void	set_bool(t_mtx *mutex, bool *dest, bool value);
bool	get_bool(t_mtx *mutex, bool *value);
void	set_long(t_mtx *mutex, long *dest, long value);
long	get_long(t_mtx *mutex, long *value);
bool	simulation_finished(t_table *table);
//synchro
void	wait_threads(t_table *table);
bool	all_threads_running(t_mtx *mutex, long *threads, long philo_nbr);
void	increase_long(t_mtx *mutex, long *value);
void	desynchro(t_philo *philo);
//monitor
void	*monitor_dinner(void *data);