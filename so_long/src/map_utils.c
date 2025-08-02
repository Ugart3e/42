/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 16:51:44 by jougarte          #+#    #+#             */
/*   Updated: 2025/06/12 18:01:30 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	check_empty_lines_in_string(char *str, t_map *game)
{
	int	i;
	int	line_start;

	if (!str)
		return ;
	i = 0;
	line_start = 1;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			if (line_start)
				ft_error("Error\nEl mapa contiene líneas vacías\n", game);
			line_start = 1;
		}
		else
		{
			line_start = 0;
		}
		i++;
	}
}

static char	*read_file_content(char *file, t_map *game)
{
	int		fd;
	char	*line;
	char	*joined;
	char	*tmp;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("Error\nNo se pudo abrir el mapa\n", game);
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
	close(fd);
	return (joined);
}

static void	validate_file_content(char *content, t_map *game)
{
	if (!content || ft_strlen(content) == 0)
	{
		free(content);
		ft_error("Error\nEl mapa está vacío\n", game);
	}
	check_empty_lines_in_string(content, game);
}

static void	set_map_dimensions(t_map *game)
{
	game->height = 0;
	while (game->map[game->height])
		game->height++;
	game->width = ft_strlen(game->map[0]);
}

void	read_map(t_map *game, char *file)
{
	char	*joined;

	joined = read_file_content(file, game);
	validate_file_content(joined, game);
	game->map = ft_split(joined, '\n');
	free(joined);
	if (!game->map || !game->map[0])
		ft_error("Error\nEl mapa está vacío\n", game);
	set_map_dimensions(game);
}
