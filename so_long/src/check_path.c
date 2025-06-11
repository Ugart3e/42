/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:00:45 by jougarte          #+#    #+#             */
/*   Updated: 2025/06/11 17:08:33 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	dfs(int y, int x, struct s_dfs_args *args)
{
	if (y < 0 || x < 0 || y >= args->height || x >= args->width)
		return ;
	if (args->map[y][x] == '1' || args->map[y][x] == 'V')
		return ;
	if (args->map[y][x] == 'C')
		args->coins_reached++;
	if (args->map[y][x] == 'E')
		args->exit_reached = 1;
	args->map[y][x] = 'V';
	dfs(y + 1, x, args);
	dfs(y - 1, x, args);
	dfs(y, x + 1, args);
	dfs(y, x - 1, args);
}

static char	*copy_row(char *row, int width)
{
	char	*copy;
	int		i;

	copy = malloc(sizeof(char) * (width + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < width)
	{
		copy[i] = row[i];
		i++;
	}
	copy[width] = '\0';
	return (copy);
}

static char	**create_map_copy(char **map, int height, int width)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = copy_row(map[i], width);
		if (!copy[i])
		{
			while (i-- > 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[height] = NULL;
	return (copy);
}

static void	free_map_copy(char **map_copy, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(map_copy[i]);
		i++;
	}
	free(map_copy);
}

int	check_path_validity(t_map *map)
{
	struct s_dfs_args	args;
	char				**map_copy;

	map_copy = create_map_copy(map->map, map->height, map->width);
	if (!map_copy)
	{
		ft_putstr_fd("Error\nNo se pudo reservar memoria para el camino\n", 2);
		exit(EXIT_FAILURE);
	}
	args.coins_reached = 0;
	args.exit_reached = 0;
	args.height = map->height;
	args.width = map->width;
	args.map = map_copy;
	dfs(map->p.y, map->p.x, &args);
	free_map_copy(map_copy, map->height);
	if (args.coins_reached != map->coin || args.exit_reached == 0)
		return (0);
	return (1);
}
