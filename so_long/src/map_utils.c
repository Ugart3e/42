/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 16:51:44 by jougarte          #+#    #+#             */
/*   Updated: 2025/06/12 11:43:25 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	read_map(t_map *game, char *file)
{
	int		fd;
	char	*line;
	char	*joined;
	char	*tmp;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("Error\nNo se pudo abrir el mapa\n");
	joined = ft_strdup("");
	line = get_next_line(fd);
	while (line != NULL)
	{
		tmp = ft_strjoin(joined, line);
		free(joined);
		free(line);
		joined = tmp;
		line = get_next_line(fd);
	}
	game->map = ft_split(joined, '\n');
	game->height = 0;
	while (game->map[game->height])
		game->height++;
	game->width = ft_strlen(game->map[0]);
	free(joined);
	close(fd);
}

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
