/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:01:04 by jougarte          #+#    #+#             */
/*   Updated: 2025/08/04 17:05:57 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
/*check rem if failure elapsed change*/
static bool	philo_died(t_philo *philo)
{
	long	elapsed;
	long	ttd;
	long	rem;

	if (get_bool(&philo->philo_mutex, &philo->full))
		return (false);
	rem = get_long(&philo->philo_mutex, &philo->last_time_meal);
	elapsed = gettime(MILISECOND) - rem;
	ttd = philo->table->time_to_die / 1e3;
	if (elapsed > ttd)
		return (true);
	return (false);
}

void	*monitor_dinner(void *data)
{
	int		i;
	t_table	*table;

	table = (t_table *)data;
	while (!all_threads_running(&table->table_mutex,
			&table->threads_running_nbr, table->philo_nbr))
		;
	while (!simulation_finished(table))
	{
		i = 0;
		while (i < table->philo_nbr && !simulation_finished(table))
		{
			if (philo_died(table->philos + i))
			{
				write_status(DIED, table->philos + i, DEBUG_MODE);
				set_bool(&table->table_mutex, &table->end_simulation, true);
			}
			i++;
		}
	}
	return (NULL);
}
