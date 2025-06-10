#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/MLX42/include/MLX42/MLX42.h"
# include "../libs/libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>


# define PXL 50
# define TILE_SIZE 64

typedef struct s_img
{
    mlx_texture_t   *wall;
    mlx_texture_t   *tile;
    mlx_texture_t   *p;
    mlx_texture_t   *coll;
    mlx_texture_t   *exit_c;
    mlx_image_t     *wall_i;
    mlx_image_t     *ti_i;
    mlx_image_t     *p_i;
    mlx_image_t     *collect_i;
    mlx_image_t     *exit_c_i;
}   t_img;

typedef struct s_player
{
    int x;
    int y;
    int player_instance;
}   t_player;

typedef struct s_map
{
    char        **map;
    char        **map_save;
    int         moves;
    t_img       img;        // Agregar estas estructuras
    t_player    p;
    int         exit;
    int         exity;
    int         exitx;
    int         exit_c;
    int         coin;
    int         coin_c;
    int         p_num;
    int         p_c;
    int         height;
    int         width;
    int         null_check;
    mlx_t       *mlx;
}   t_map;

// Funciones de renderizado
void	load_textures(t_map *game);
void	load_images(t_map *game);
void	init_map(t_map *game);
void	create_map(t_map *game);

// Funciones de ventana
void	close_window(mlx_key_data_t keydata, void *param);
void	open_window(t_map *game);

// Funciones de movimiento y callbacks
void	key_hook(mlx_key_data_t keydata, void *param);
void	close_hook(void *param);
void	move_player(t_map *game, int new_x, int new_y);
void	find_player_position(t_map *game);
int	is_valid_move(t_map *game, int new_x, int new_y);  // Agregar este también

// Funciones de validación
int	check_valid_chars_and_counts(t_map *map);
int	check_rectangular(t_map *map);
int	check_walls(t_map *map);
void	ft_error(char *msg);
int	check_path_validity(t_map *map);

#endif