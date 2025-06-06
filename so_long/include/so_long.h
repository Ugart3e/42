#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libs/MLX42/include/MLX42/MLX42.h"
# include "../libs/libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

# define PXL 50

typedef struct s_p
{
	int	y;
	int	x;
}	t_p;

typedef struct s_img
{
	mlx_texture_t	*coll;
	mlx_texture_t	*wall;
	mlx_texture_t	*exit_c;
	mlx_texture_t	*exit_o;
	mlx_texture_t	*p;
	mlx_texture_t	*tile;
	mlx_image_t		*collect_i;
	mlx_image_t		*wall_i;
	mlx_image_t		*exit_c_i;
	mlx_image_t		*exit_o_i;
	mlx_image_t		*p_i;
	mlx_image_t		*ti_i;
}	t_img;

typedef struct s_map
{
	char		**map;
	char		**map_save;
	int			moves;
	t_img		img;
	t_p			p;
	int			exit;
	int			exity;
	int			exitx;
	int			exit_c;
	int			coin;
	int			coin_c;
	int			p_num;
	int			p_c;
	int			height;
	int			width;
	int			null_check;
	mlx_t		*wind;
}	t_map;

int map_check(t_map *map);

#endif