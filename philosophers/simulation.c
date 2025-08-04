/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:22:36 by jougarte          #+#    #+#             */
/*   Updated: 2025/08/04 22:09:55 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*lonely(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	wait_threads(philo->table);
	set_long(&philo->philo_mutex, &philo->last_time_meal, gettime(MILISECOND));
	increase_long(&philo->table->table_mutex,
		&philo->table->threads_running_nbr);
	write_status(TAKE_FIRST_FORK, philo, DEBUG_MODE);
	while (!simulation_finished(philo->table))
		usleep(200);
	return (NULL);
}

static void	eat(t_philo *philo)
{
	safe_mutex_handle(&philo->fork1->fork, LOCK);
	if (simulation_finished(philo->table))
	{
		safe_mutex_handle(&philo->fork1->fork, UNLOCK);
		return ;
	}
	write_status(TAKE_FIRST_FORK, philo, DEBUG_MODE);
	safe_mutex_handle(&philo->fork2->fork, LOCK);
	if (simulation_finished(philo->table))
	{
		safe_mutex_handle(&philo->fork2->fork, UNLOCK);
		safe_mutex_handle(&philo->fork1->fork, UNLOCK);
		return ;
	}
	write_status(TAKE_SECOND_FORK, philo, DEBUG_MODE);
	set_long(&philo->philo_mutex, &philo->last_time_meal, gettime(MILISECOND));
	philo->nbr_meals++;
	write_status(EATING, philo, DEBUG_MODE);
	ft_usleep(philo->table->time_to_eat, philo->table);
	if (philo->table->nbr_limit_meals > 0
		&&philo->nbr_meals == philo->table->nbr_limit_meals)
		set_bool(&philo->philo_mutex, &philo->full, true);
	safe_mutex_handle(&philo->fork1->fork, UNLOCK);
	safe_mutex_handle(&philo->fork2->fork, UNLOCK);
}

//avoiding philo eating 2 times in a row
void	think(t_philo *philo, bool pre_sim)
{
    int	thinking_time;

    if (!pre_sim)
        write_status(THINKING, philo, DEBUG_MODE);
    thinking_time = philo->table->time_to_eat - philo->table->time_to_sleep;
    if (thinking_time < 10) // mínimo 10ms
        thinking_time = 10;
    ft_usleep(thinking_time, philo->table);
}

void	*dinner_simulation(void *data)
{
    t_philo	*philo;

    philo = (t_philo *)data;
    wait_threads(philo->table);
    set_long(&philo->philo_mutex, &philo->last_time_meal, gettime(MILISECOND));
    increase_long(&philo->table->table_mutex,
        &philo->table->threads_running_nbr);
    desynchro(philo);
    while (!simulation_finished(philo->table))
    {
        eat(philo);
        write_status(SLEEPING, philo, DEBUG_MODE);
        ft_usleep(philo->table->time_to_sleep, philo->table);
        think(philo, false);
        if (philo->full)
            break ;
    }
    return (NULL);
}

void	init_simulation(t_table *table)
{
	int	i;

	check_sim_type(table);
	safe_thread_handle(&table->monitor, monitor_dinner, table, CREATE);
	set_bool(&table->table_mutex, &table->threads_ready, true);
	i = 0;
	while (i < table->philo_nbr)
	{
		safe_thread_handle(&table->philos[i].thread_id, NULL, NULL, JOIN);
		i++;
	}
	set_bool(&table->table_mutex, &table->end_simulation, true);
	safe_thread_handle(&table->monitor, NULL, NULL, JOIN);
	check_death(table);
}
