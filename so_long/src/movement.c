#include "../include/so_long.h"

void	find_player_position(t_map *game)
{
    int y = 0;
    int x = 0;
    
    while (y < game->height)
    {
        x = 0;
        while (x < game->width)
        {
            if (game->map[y][x] == 'P')
            {
                game->p.x = x;
                game->p.y = y;
                return;
            }
            x++;
        }
        y++;
    }
}

int	is_valid_move(t_map *game, int new_x, int new_y)
{
    if (new_x < 0 || new_x >= game->width || new_y < 0 || new_y >= game->height)
        return (0);
    if (game->map[new_y][new_x] == '1')
        return (0);
    if (game->map[new_y][new_x] == 'E' && game->coin_c > 0)
        return (0);
    return (1);
}

void	move_player(t_map *game, int new_x, int new_y)
{
    if (!is_valid_move(game, new_x, new_y))
        return ;
    
    if (game->map[new_y][new_x] == 'C')
    {
        game->coin_c--;
        game->map[new_y][new_x] = '0';
    }
    
    if (game->map[new_y][new_x] == 'E' && game->coin_c == 0)
    {
        mlx_close_window(game->mlx);
        return ;
    }
    
    // Usar el índice correcto del jugador guardado en create_map
    game->img.p_i->instances[game->p.player_instance].x = new_x * TILE_SIZE;
    game->img.p_i->instances[game->p.player_instance].y = new_y * TILE_SIZE;
    
    // Actualizar posición lógica
    game->p.x = new_x;
    game->p.y = new_y;
    
    game->moves++;
    ft_printf("Movimientos: %d\n", game->moves);  // Debug
}

void key_hook(mlx_key_data_t keydata, void *param)
{
    t_map *game = (t_map *)param;
    
    if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
        mlx_close_window(game->mlx);
    
    if (keydata.action == MLX_PRESS)
    {
        if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
            move_player(game, game->p.x, game->p.y - 1);
        else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
            move_player(game, game->p.x, game->p.y + 1);
        else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
            move_player(game, game->p.x - 1, game->p.y);
        else if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
            move_player(game, game->p.x + 1, game->p.y);
    }
}

void	close_hook(void *param)
{
    t_map *game = (t_map *)param;
    ft_printf("Cerrando ventana...\n");
    mlx_terminate(game->mlx);
    exit(0);
}