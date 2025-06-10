#include "../include/so_long.h"

void	load_textures(t_map *game)
{
    ft_printf("Cargando texturas...\n"); // Debug
    
    game->img.wall = mlx_load_png("textures/wall.png");
    if (!game->img.wall)
    {
        ft_printf("Error: No se encontró textures/wall.png\n");
        ft_error("Error\nNo se pudo cargar wall.png\n");
    }
    
    game->img.tile = mlx_load_png("textures/floor.png");
    if (!game->img.tile)
        ft_error("Error\nNo se pudo cargar floor.png - verifica que el archivo exista\n");
    
    game->img.p = mlx_load_png("textures/player.png");
    if (!game->img.p)
        ft_error("Error\nNo se pudo cargar player.png - verifica que el archivo exista\n");
    
    game->img.coll = mlx_load_png("textures/coin.png");
    if (!game->img.coll)
        ft_error("Error\nNo se pudo cargar coin.png - verifica que el archivo exista\n");
    
    game->img.exit_c = mlx_load_png("textures/exit.png");
    if (!game->img.exit_c)
        ft_error("Error\nNo se pudo cargar exit.png - verifica que el archivo exista\n");
    
    if (!game->img.wall || !game->img.tile || !game->img.p ||
        !game->img.coll || !game->img.exit_c)
        ft_error("Error\nNo se pudieron cargar las texturas\n");
    
    ft_printf("Texturas cargadas exitosamente\n"); // Debug
}

void	load_images(t_map *game)
{
    game->img.wall_i = mlx_texture_to_image(game->mlx, game->img.wall);
    game->img.ti_i = mlx_texture_to_image(game->mlx, game->img.tile);
    game->img.p_i = mlx_texture_to_image(game->mlx, game->img.p);
    game->img.collect_i = mlx_texture_to_image(game->mlx, game->img.coll);
    game->img.exit_c_i = mlx_texture_to_image(game->mlx, game->img.exit_c);
    
    if (!game->img.wall_i || !game->img.ti_i || !game->img.p_i ||
        !game->img.collect_i || !game->img.exit_c_i)
        ft_error("Error\nNo se pudieron crear las imágenes\n");
}

void	init_map(t_map *game)
{
    int x, y;
    
    load_textures(game);
    load_images(game);
    
    // Renderizar mapa estático (una sola vez)
    y = 0;
    while (y < game->height)
    {
        x = 0;
        while (x < game->width)
        {
            if (game->map[y][x] == '1')
                mlx_image_to_window(game->mlx, game->img.wall_i, x * TILE_SIZE, y * TILE_SIZE);
            else
                mlx_image_to_window(game->mlx, game->img.ti_i, x * TILE_SIZE, y * TILE_SIZE);
            
            // Renderizar elementos estáticos
            if (game->map[y][x] == 'E')
                mlx_image_to_window(game->mlx, game->img.exit_c_i, x * TILE_SIZE, y * TILE_SIZE);
            else if (game->map[y][x] == 'C')
                mlx_image_to_window(game->mlx, game->img.collect_i, x * TILE_SIZE, y * TILE_SIZE);
            else if (game->map[y][x] == 'P')
            {
                mlx_image_to_window(game->mlx, game->img.p_i, x * TILE_SIZE, y * TILE_SIZE);
                // Guardar el índice de la instancia del jugador
                game->p.player_instance = game->img.p_i->count - 1;
            }
            x++;
        }
        y++;
    }
}

// Solo para debugging - no usar durante el juego
void	create_map(t_map *game)
{
    init_map(game);
}