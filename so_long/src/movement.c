/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 16:54:43 by jougarte          #+#    #+#             */
/*   Updated: 2025/06/11 16:54:44 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	is_valid_move(t_map *game, int new_x, int new_y)
{
	if (new_x < 0 || new_x >= game->width
		|| new_y < 0 || new_y >= game->height)
		return (0);
	if (game->map[new_y][new_x] == '1')
		return (0);
	if (game->map[new_y][new_x] == 'E' && game->coin_c > 0)
		return (0);
	return (1);
}

static void	disable_collected(t_map *game, int x, int y)
{
	size_t	i;

	i = 0;
	while (i < game->img.collect_i->count)
	{
		if (game->img.collect_i->instances[i].x == x * TILE_SIZE
			&& game->img.collect_i->instances[i].y == y * TILE_SIZE)
		{
			game->img.collect_i->instances[i].enabled = false;
			break ;
		}
		i++;
	}
}

static void	handle_collect_or_exit(t_map *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == 'C')
	{
		game->coin_c--;
		disable_collected(game, new_x, new_y);
	}
	if (game->map[new_y][new_x] == 'E' && game->coin_c == 0)
	{
		ft_printf("¡Nivel completado en %d movimientos!\n", game->moves + 1);
		mlx_close_window(game->mlx);
	}
}

void	move_player(t_map *game, int new_x, int new_y)
{
	if (!is_valid_move(game, new_x, new_y))
		return ;
	mlx_image_to_window(game->mlx, game->img.ti_i,
		game->p.x * TILE_SIZE, game->p.y * TILE_SIZE);
	handle_collect_or_exit(game, new_x, new_y);
	if (game->map[new_y][new_x] == 'E' && game->coin_c == 0)
		return ;
	game->map[game->p.y][game->p.x] = '0';
	game->p.x = new_x;
	game->p.y = new_y;
	game->map[new_y][new_x] = 'P';
	mlx_image_to_window(game->mlx, game->img.p_i,
		new_x * TILE_SIZE, new_y * TILE_SIZE);
	game->moves++;
	ft_printf("Movimientos: %d\n", game->moves);
	if (game->coin_c == 0)
		ft_printf("¡Todos los coleccionables recogidos! Ahora puedes salir.\n");
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_map	*game;
	int		new_x;
	int		new_y;

	game = (t_map *)param;
	new_x = game->p.x;
	new_y = game->p.y;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
			new_y--;
		else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
			new_y++;
		else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
			new_x--;
		else if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
			new_x++;
		move_player(game, new_x, new_y);
	}
}
