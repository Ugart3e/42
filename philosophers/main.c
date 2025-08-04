/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:53:56 by jougarte          #+#    #+#             */
/*   Updated: 2025/08/04 16:58:27 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	parse_input(t_table *table, char **av, int ac)
{
	int		i;
	long	val;

	i = 1;
	while (i < ac)
	{
		val = atol(av[i]);
		if (val > INT_MAX || val <= 0)
			ft_error("Invalid value: must be a positive integer in range.");
		i++;
	}
	table->philo_nbr = ft_atol(av[1]);
	table->time_to_die = ft_atol(av[2]) * 1e3;
	table->time_to_eat = ft_atol(av[3]) * 1e3;
	table->time_to_sleep = ft_atol(av[4]) * 1e3;
	if (ac == 6)
		table->nbr_limit_meals = ft_atol(av[5]);
	else
		table->nbr_limit_meals = -1;
}

int	main(int ac, char **av)
{
	t_table	table;

	if (ac != 5 && ac != 6)
		ft_error("Wrong input, please retry\n");
	parse_input(&table, av, ac);
	data_init(&table);
	init_simulation(&table);
	clean_data(&table);
	return (0);
}
