#include "../include/so_long.h"
#include <fcntl.h>

void	read_map(t_map *game, char *file)
{
	int		fd;
	char	*line;
	char	*joined;
	char	*tmp;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nNo se pudo abrir el mapa\n", 2);
		exit(1);
	}
	line = NULL;
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
	free(joined);
	close(fd);
}

int	check_ber_extension(char *filename)
{
	int	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	return (ft_strncmp(filename + len - 4, ".ber", 4) == 0);
}

int	main(int ac, char **av)
{
	t_map map;
	int i;

	if (ac == 2 && check_ber_extension(av[1]))
	{
		read_map(&map, av[1]);
		i = 0;
		while (map.map[i])
		{
			ft_printf("%s\n", map.map[i]);
			i++;
		}
		if (!check_valid_chars_and_counts(&map))
			ft_error("Error\nCaracter inválido en el mapa\n");
		if (map.p_num != 1)
			ft_error("Error\nDebe haber exactamente una posición inicial\n");
		if (map.exit < 1)
			ft_error("Error\nDebe haber al menos una salida\n");
		if (map.coin < 1)
			ft_error("Error\nDebe haber al menos un coleccionable\n");
		if (!check_rectangular(&map))
			ft_error("Error\nEl mapa no es rectangular\n");
		if (!check_walls(&map))
			ft_error("Error\nEl mapa no está cerrado por muros\n");
		if (!check_path_validity(&map))
			ft_error("Error\nNo hay un camino válido a todas las monedas y a la salida\n");
	}
	else
		ft_printf("Error\n");

	return 0;
}