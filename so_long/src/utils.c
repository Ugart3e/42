/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:53:45 by jougarte          #+#    #+#             */
/*   Updated: 2025/06/12 18:06:54 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_ber_extension(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	return (ft_strncmp(filename + len - 4, ".ber", 4) == 0);
}

void	cleanup_game(t_map *game)
{
	if (game->img.wall)
		mlx_delete_texture(game->img.wall);
	if (game->img.tile)
		mlx_delete_texture(game->img.tile);
	if (game->img.p)
		mlx_delete_texture(game->img.p);
	if (game->img.coll)
		mlx_delete_texture(game->img.coll);
	if (game->img.exit_c)
		mlx_delete_texture(game->img.exit_c);
	cleanup_images(game);
	if (game->map)
		free_map(game->map, game->height);
	if (game->map_save)
		free_map(game->map_save, game->height);
}

void	render_tile(t_map *game, int x, int y)
{
	if (game->map[y][x] == '1')
		mlx_image_to_window(game->mlx, game->img.wall_i,
			x * TILE_SIZE, y * TILE_SIZE);
	else
		mlx_image_to_window(game->mlx, game->img.ti_i,
			x * TILE_SIZE, y * TILE_SIZE);
}

void	cleanup_images(t_map *game)
{
	if (game->img.wall_i)
	{
		mlx_delete_image(game->mlx, game->img.wall_i);
		game->img.wall_i = NULL;
	}
	if (game->img.ti_i)
	{
		mlx_delete_image(game->mlx, game->img.ti_i);
		game->img.ti_i = NULL;
	}
	if (game->img.p_i)
	{
		mlx_delete_image(game->mlx, game->img.p_i);
		game->img.p_i = NULL;
	}
	if (game->img.collect_i)
	{
		mlx_delete_image(game->mlx, game->img.collect_i);
		game->img.collect_i = NULL;
	}
	if (game->img.exit_c_i)
	{
		mlx_delete_image(game->mlx, game->img.exit_c_i);
		game->img.exit_c_i = NULL;
	}
}

void	free_map(char **map, int height)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (i < height)
	{
		if (map[i])
			free(map[i]);
		i++;
	}
	free(map);
}
