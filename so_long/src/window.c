/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 16:26:45 by jougarte          #+#    #+#             */
/*   Updated: 2025/06/11 16:36:00 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	close_window(mlx_key_data_t keydata, void *param)
{
	t_map	*game;

	game = (t_map *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
}

void	open_window(t_map *game)
{
	game->mlx = mlx_init(game->width * 64, game->height * 64, "so_long", true);
	if (!game->mlx)
		ft_error("Error\nNo se pudo inicializar MLX\n");
	find_player_position(game);
	create_map(game);
	mlx_key_hook(game->mlx, key_hook, game);
	mlx_close_hook(game->mlx, close_hook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
}
