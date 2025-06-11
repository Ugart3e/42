/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 16:55:00 by jougarte          #+#    #+#             */
/*   Updated: 2025/06/11 16:55:14 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	find_player_position(t_map *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'P')
			{
				game->p.x = x;
				game->p.y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	close_hook(void *param)
{
	t_map	*game;

	game = (t_map *)param;
	mlx_terminate(game->mlx);
	exit(0);
}
