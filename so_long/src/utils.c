/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:53:45 by jougarte          #+#    #+#             */
/*   Updated: 2025/06/12 15:54:09 by jougarte         ###   ########.fr       */
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
