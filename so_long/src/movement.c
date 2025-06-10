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
    // Verificar límites del mapa
    if (new_x < 0 || new_x >= game->width || new_y < 0 || new_y >= game->height)
        return (0);
    
    // No se puede mover a una pared
    if (game->map[new_y][new_x] == '1')
        return (0);
    
    // No se puede entrar a la salida si aún hay coleccionables
    if (game->map[new_y][new_x] == 'E' && game->coin_c > 0)
        return (0);
    
    return (1);  // Movimiento válido
}

void move_player(t_map *game, int new_x, int new_y)
{
    // ✅ PRIMERO: Verificar si el movimiento es válido
    if (!is_valid_move(game, new_x, new_y))
        return;  // Si no es válido, no hacer nada
    
    // Borrar la imagen anterior del jugador
    mlx_image_to_window(game->mlx, game->img.ti_i, game->p.x * TILE_SIZE, game->p.y * TILE_SIZE);
    
    // Verificar si hay un coleccionable en la nueva posición ANTES de mover
    if (game->map[new_y][new_x] == 'C')
    {
        game->coin_c--;
        ft_printf("Coleccionables restantes: %d\n", game->coin_c);
        
        // Deshabilitar la imagen del coleccionable
        size_t i = 0;
        while (i < game->img.collect_i->count)
        {
            if (game->img.collect_i->instances[i].x == new_x * TILE_SIZE && 
                game->img.collect_i->instances[i].y == new_y * TILE_SIZE)
            {
                game->img.collect_i->instances[i].enabled = false;
                break;
            }
            i++;
        }
    }
    
    // Verificar si el jugador llegó a la salida con todos los coleccionables
    if (game->map[new_y][new_x] == 'E' && game->coin_c == 0)
    {
        ft_printf("¡Felicidades! Has completado el nivel en %d movimientos.\n", game->moves + 1);
        mlx_close_window(game->mlx);
        return;  // Salir de la función para evitar seguir procesando
    }
    
    // Actualizar la posición del jugador en el mapa
    game->map[game->p.y][game->p.x] = '0';
    game->p.x = new_x;
    game->p.y = new_y;
    game->map[new_y][new_x] = 'P';
    
    // Dibujar el jugador en la nueva posición
    mlx_image_to_window(game->mlx, game->img.p_i, new_x * TILE_SIZE, new_y * TILE_SIZE);
    
    // Incrementar contador de movimientos
    game->moves++;
    ft_printf("Movimientos: %d\n", game->moves);
    
    // Verificar si se han recogido todos los coleccionables
    if (game->coin_c == 0)
    {
        ft_printf("¡Todos los coleccionables recogidos! Ahora puedes salir.\n");
    }
}

void key_hook(mlx_key_data_t keydata, void *param)
{
    t_map *game = (t_map *)param;
    
    if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
        mlx_close_window(game->mlx);
    
    if (keydata.action == MLX_PRESS)
    {
        // ✅ Calcular nueva posición según la tecla presionada
        int new_x = game->p.x;
        int new_y = game->p.y;
        
        if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
            new_y--;
        else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
            new_y++;
        else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
            new_x--;
        else if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
            new_x++;
        else
            return;  // Si no es una tecla de movimiento, no hacer nada
        
        // Intentar mover al jugador (la validación se hace dentro de move_player)
        move_player(game, new_x, new_y);
    }
}

void	close_hook(void *param)
{
    t_map *game = (t_map *)param;
    ft_printf("Cerrando ventana...\n");
    mlx_terminate(game->mlx);
    exit(0);
}