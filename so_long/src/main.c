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

	joined = ft_strdup("");
	while ((line = get_next_line(fd)))
	{
		tmp = ft_strjoin(joined, line);
		free(joined);
		free(line);
		joined = tmp;
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

	ft_bzero(&map, sizeof(t_map));

	if (ac == 2 && check_ber_extension(av[1]))
	{
		read_map(&map, av[1]);
		i = 0;
		while (map.map[i])
		{
			ft_printf("%s\n", map.map[i]);
			i++;
		}
	}
	else
		ft_printf("Error\n");

	return 0;
}