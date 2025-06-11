/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 16:30:06 by jougarte          #+#    #+#             */
/*   Updated: 2025/06/11 16:43:27 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_valid_chars_and_counts(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->p_num = 0;
	map->exit = 0;
	map->coin = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (!process_map_char(map, i, j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	process_map_char(t_map *map, int i, int j)
{
	char	c;

	c = map->map[i][j];
	if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P')
		return (0);
	if (c == 'P')
	{
		map->p_num++;
		map->p.y = i;
		map->p.x = j;
	}
	else if (c == 'E')
		map->exit++;
	else if (c == 'C')
		map->coin++;
	return (1);
}

int	check_rectangular(t_map *map)
{
	int	len;
	int	i;

	i = 1;
	len = ft_strlen(map->map[0]);
	map->width = len;
	map->height = 0;
	while (map->map[i])
	{
		if ((int)ft_strlen(map->map[i]) != len)
			return (0);
		i++;
	}
	map->height = i;
	return (1);
}

int	check_walls(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->width)
	{
		if (map->map[0][i] != '1' || map->map[map->height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if (map->map[i][0] != '1' || map->map[i][map->width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	ft_error(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}
