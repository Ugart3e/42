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
	
	// Calcular dimensiones del mapa
	game->height = 0;
	while (game->map[game->height])
		game->height++;
	game->width = ft_strlen(game->map[0]);
	
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

void cleanup_game(t_map *game)
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

int	main(int ac, char **av)
{
    t_map map;
    int i;

    if (ac == 2 && check_ber_extension(av[1]))
    {
        // ✅ INICIALIZAR la estructura completa al principio
        ft_memset(&map, 0, sizeof(t_map));
        
        read_map(&map, av[1]);
        i = 0;
        while (map.map[i])
        {
            ft_printf("%s\n", map.map[i]);
            i++;
        }
        
        // Las validaciones necesitan que estas variables estén inicializadas
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
    
        // ✅ INICIALIZAR contador de monedas DESPUÉS de las validaciones
        map.coin_c = map.coin;  // Ahora map.coin ya tiene el valor correcto
        map.moves = 0;
        
        // Inicializar MLX
        map.mlx = mlx_init(map.width * TILE_SIZE, map.height * TILE_SIZE, "so_long", true);
        if (!map.mlx)
            ft_error("Error\nNo se pudo inicializar MLX\n");
    
        create_map(&map);
        
        // ✅ AGREGAR: Encontrar la posición inicial del jugador
        find_player_position(&map);
        
        ft_printf("Jugador en posición: (%d, %d)\n", map.p.x, map.p.y); // Debug
        
        ft_printf("Registrando callbacks...\n"); // Debug
        // Registrar callbacks para mantener la ventana activa
        mlx_key_hook(map.mlx, key_hook, &map);
        mlx_close_hook(map.mlx, close_hook, &map);
        
        ft_printf("Iniciando bucle MLX...\n"); // Debug
        // Bucle principal de MLX - esto mantiene la ventana abierta
        mlx_loop(map.mlx);
        
        // Esto solo se ejecuta cuando se cierra la ventana
        cleanup_game(&map);
        mlx_terminate(map.mlx);
    }
    else
        ft_printf("Error\n");

    return 0;
}