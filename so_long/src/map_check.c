#include "../include/so_long.h"
int	check_valid_chars_and_counts(t_map *map)
{
	int i = 0, j;

	map->p_num = 0;
	map->exit = 0;
	map->coin = 0;

	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] != '0' && map->map[i][j] != '1' && map->map[i][j] != 'C' &&
				map->map[i][j] != 'E' && map->map[i][j] != 'P')
				return (0); // Caracter no válido
            if (map->map[i][j] == 'P')
            {
	            map->p_num++;
	            map->p.y = i;
	            map->p.x = j;
            }
			else if (map->map[i][j] == 'E')
				map->exit++;
			else if (map->map[i][j] == 'C')
				map->coin++;
			j++;
		}
		i++;
	}
	return (1);
}

int	check_rectangular(t_map *map)
{
	int	len;
	int	i = 1;

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
	int	len = map->width;
	int	rows = map->height;

	// Primera y última fila deben ser solo '1'
	for (i = 0; i < len; i++)
	{
		if (map->map[0][i] != '1' || map->map[rows - 1][i] != '1')
			return (0);
	}
	// Primera y última columna de cada fila deben ser '1'
	for (i = 0; i < rows; i++)
	{
		if (map->map[i][0] != '1' || map->map[i][len - 1] != '1')
			return (0);
	}
	return (1);
}

void	ft_error(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}