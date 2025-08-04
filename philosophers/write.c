/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:47:52 by jougarte          #+#    #+#             */
/*   Updated: 2025/08/04 17:53:37 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_status(t_philo_state status, t_philo *philo, long elapsed)
{
	if (TAKE_FIRST_FORK == status || TAKE_SECOND_FORK == status
		&& !simulation_finished(philo->table))
		printf("%-6ld %d has taken a fork\n", elapsed, philo->id);
	else if (EATING == status && !simulation_finished(philo->table))
		printf("%-6ld %d is eating\n", elapsed, philo->id);
	else if (SLEEPING == status && !simulation_finished(philo->table))
		printf("%-6ld %d is sleeping\n", elapsed, philo->id);
	else if (THINKING == status && !simulation_finished(philo->table))
		printf("%-6ld %d is thinking\n", elapsed, philo->id);
	else if (DIED == status && !simulation_finished(philo->table))
		printf("%-6ld %d died\n", elapsed, philo->id);
}

static void	debug_status(t_philo_state status, t_philo *philo, long elapsed)
{
	if (TAKE_FIRST_FORK == status && !simulation_finished(philo->table))
		printf("%-6ld %d Has taken fork1\n", elapsed, philo->id);
	else if (TAKE_SECOND_FORK == status && !simulation_finished(philo->table))
		printf("%-6ld %d Has taken fork2\n", elapsed, philo->id);
	else if (EATING == status && !simulation_finished(philo->table))
		printf("%-6ld %d Is eating\n", elapsed, philo->id);
	else if (SLEEPING == status && !simulation_finished(philo->table))
		printf("%-6ld %d Is sleeping\n", elapsed, philo->id);
	else if (THINKING == status && !simulation_finished(philo->table))
		printf("%-6ld %d Is thinking\n", elapsed, philo->id);
	else if (DIED == status && !simulation_finished(philo->table))
		printf("%-6ld %d died\n", elapsed, philo->id);
}

void	write_status(t_philo_state status, t_philo *philo, bool debug)
{
	long	elapsed;

	safe_mutex_handle(&philo->table->write_mutex, LOCK);
	elapsed = gettime(MILISECOND) - philo->table->start_simulation_time;
	if (philo->full)
	{
		safe_mutex_handle(&philo->table->write_mutex, UNLOCK);
		return ;
	}
	if (debug)
		debug_status(status, philo, elapsed);
	else
	{
		print_status(status, philo, elapsed);
	}
	safe_mutex_handle(&philo->table->write_mutex, UNLOCK);
}

void	check_sim_type(t_table *table)
{
	int	i;

	i = 0;
	if (0 == table->nbr_limit_meals)
		return ;
	if (1 == table->philo_nbr)
	{
		lonely_init(table);
		return ;
	}
	else
	{
		table->start_simulation_time = gettime(MILISECOND);
		while (i < table->philo_nbr)
		{
			safe_thread_handle(&table->philos[i].thread_id, dinner_simulation,
				&table->philos[i], CREATE);
			i++;
		}
	}
}
