/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 16:51:57 by jougarte          #+#    #+#             */
/*   Updated: 2025/06/12 14:02:08 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	validate_map(t_map *map)
{
	if (!check_rectangular(map))
		ft_error("Error\nEl mapa no es rectangular\n");
	if (!check_valid_chars_and_counts(map))
		ft_error("Error\nCaracter inválido en el mapa\n");
	if (map->p_num != 1)
		ft_error("Error\nDebe haber exactamente una posición inicial\n");
	if (map->exit != 1)
		ft_error("Error\nDebe haber exactamente una salida\n");
	if (map->coin < 1)
		ft_error("Error\nDebe haber al menos un coleccionable\n");
	if (!check_walls(map))
		ft_error("Error\nEl mapa no está cerrado por muros\n");
	if (!check_path_validity(map))
		ft_error("Error\nNo hay un camino válido a todos los elementos\n");
}

void	print_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		ft_printf("%s\n", map->map[i]);
		i++;
	}
}

void	init_and_run_game(t_map *map)
{
	map->coin_c = map->coin;
	map->moves = 0;
	map->mlx = mlx_init(map->width * TILE_SIZE,
			map->height * TILE_SIZE, "so_long", true);
	if (!map->mlx)
		ft_error("Error\nNo se pudo inicializar MLX\n");
	create_map(map);
	find_player_position(map);
	mlx_key_hook(map->mlx, key_hook, map);
	mlx_close_hook(map->mlx, close_hook, map);
	mlx_loop(map->mlx);
	cleanup_game(map);
	mlx_terminate(map->mlx);
}

int	main(int ac, char **av)
{
	t_map	map;

	if (ac == 2 && check_ber_extension(av[1]))
	{
		ft_memset(&map, 0, sizeof(t_map));
		read_map(&map, av[1]);
		print_map(&map);
		validate_map(&map);
		init_and_run_game(&map);
	}
	else
		ft_printf("Error\n");
	return (0);
}
