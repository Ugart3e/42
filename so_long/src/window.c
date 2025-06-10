#include "../include/so_long.h"

void	close_window(mlx_key_data_t keydata, void *param)
{
    t_map *game = (t_map *)param;
    
    if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
        mlx_close_window(game->mlx);
}

void	open_window(t_map *game)
{
    game->mlx = mlx_init(game->width * TILE_SIZE, game->height * TILE_SIZE, "so_long", true);
    if (!game->mlx)
        ft_error("Error\nNo se pudo inicializar MLX\n");
    
    find_player_position(game);
    create_map(game);
    
    // Cambiar handle_keypress por key_hook (que ya existe en movement.c)
    mlx_key_hook(game->mlx, key_hook, game);
    mlx_close_hook(game->mlx, close_hook, game);
    
    mlx_loop(game->mlx);
    mlx_terminate(game->mlx);
}