/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:50:36 by jougarte          #+#    #+#             */
/*   Updated: 2025/08/04 16:53:28 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//i use &forks to not loose the real mutex, only saving copies (with pointers)
static void	assign_forks(t_philo *philo, t_fork *forks, int pos)
{
	int	philo_nbr;

	philo_nbr = philo->table->philo_nbr;
	philo->fork1 = &forks[(pos + 1) % philo_nbr];
	philo->fork2 = &forks[pos];
	if (philo->id % 2 == 0)
	{
		philo->fork1 = &forks[pos];
		philo->fork2 = &forks[(pos + 1) % philo_nbr];
	}
}

static void	philo_init(t_table *table)
{
	int		i;
	t_philo	*philo;

	i = 0;
	while (i < table->philo_nbr)
	{
		philo = table->philos + i;
		philo->id = i + 1;
		philo->full = false;
		safe_mutex_handle(&philo->philo_mutex, INIT);
		philo->nbr_meals = 0;
		philo->table = table;
		assign_forks(philo, table->forks, i);
		i++;
	}
}

void	data_init(t_table *table)
{
	int		i;

	i = 0;
	table->end_simulation = false;
	table->threads_ready = false;
	table->threads_running_nbr = 0;
	safe_mutex_handle(&table->table_mutex, INIT);
	safe_mutex_handle(&table->write_mutex, INIT);
	table->philos = safe_malloc(sizeof(t_philo) * table->philo_nbr);
	table->forks = safe_malloc(sizeof(t_fork) * table->philo_nbr);
	while (i < table->philo_nbr)
	{
		safe_mutex_handle(&table->forks[i].fork, INIT);
		table->forks[i].id = i;
		i++;
	}
	philo_init(table);
}
