#include "../include/so_long.h"
#include <stdlib.h>

// Copiar el mapa para no modificar el original
static char **copy_map(char **map, int height, int width)
{
	char **copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return NULL;

	for (int i = 0; i < height; i++)
	{
		copy[i] = malloc(sizeof(char) * (width + 1));
		if (!copy[i])
		{
			while (i-- > 0)
				free(copy[i]);
			free(copy);
			return NULL;
		}
		for (int j = 0; j < width; j++)
			copy[i][j] = map[i][j];
		copy[i][width] = '\0';
	}
	copy[height] = NULL;
	return copy;
}

// DFS para marcar las posiciones accesibles
static void	dfs(char **map, int y, int x, int height, int width, int *coins_reached, int *exit_reached)
{
	if (y < 0 || x < 0 || y >= height || x >= width)
		return;
	if (map[y][x] == '1' || map[y][x] == 'V')
		return;

	if (map[y][x] == 'C')
		(*coins_reached)++;
	if (map[y][x] == 'E')
		(*exit_reached) = 1;

	map[y][x] = 'V';

	dfs(map, y + 1, x, height, width, coins_reached, exit_reached);
	dfs(map, y - 1, x, height, width, coins_reached, exit_reached);
	dfs(map, y, x + 1, height, width, coins_reached, exit_reached);
	dfs(map, y, x - 1, height, width, coins_reached, exit_reached);
}

int	check_path_validity(t_map *map)
{
	int		coins_reached = 0;
	int		exit_reached = 0;
	int		start_y = map->p.y;
	int		start_x = map->p.x;
	char	**map_copy;

	map_copy = copy_map(map->map, map->height, map->width);
	if (!map_copy)
	{
		ft_putstr_fd("Error\nNo se pudo reservar memoria para verificar camino\n", 2);
		exit(EXIT_FAILURE);
	}

	dfs(map_copy, start_y, start_x, map->height, map->width, &coins_reached, &exit_reached);

	for (int i = 0; i < map->height; i++)
		free(map_copy[i]);
	free(map_copy);

	if (coins_reached != map->coin || exit_reached == 0)
		return 0;

	return 1;
}
