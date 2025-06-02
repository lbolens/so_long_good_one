/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolens <lbolens@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:29:26 by lbolens           #+#    #+#             */
/*   Updated: 2025/06/02 14:51:51 by lbolens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "../so_long.h"

void	doing_it(t_game *game, int *width_px, int *heigth_px)
{
	if (!game || !game->map.map || !width_px || !heigth_px)
	{
		ft_printf("Error\nInvalid pointers in doing_it\n");
		exit(1);
	}
	*width_px = number_columns(game->map.map[0]) * TILE_SIZE;
	*heigth_px = number_lines(game->map.map) * TILE_SIZE;
	init_game(game, game->map.map);
	game->window = mlx_new_window(game->mlx, *width_px, *heigth_px, "so_long");
	if (!game->window)
	{
		destroy_game(game);
		exit(1);
	}
	render_map(game, 0, 0);
	mlx_key_hook(game->window, key_handler, game);
	mlx_hook(game->window, 17, 0, close_game, game);
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_loop(game->mlx);
	destroy_game(game);
}

static void	reduce_main(t_game *game)
{
	int	width_px;
	int	height_px;

	width_px = 0;
	height_px = 0;
	doing_it(game, &width_px, &height_px);
}

static int	reduce_main_bis(char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
	{
		ft_printf("Error\nFailed to allocate memory for game structure\n");
		return (1);
	}
	game->mlx = NULL;
	game->window = NULL;
	game->asteroid = NULL;
	game->map.map = NULL;
	game->map.map = is_map_valid(argv[1], 0, 0);
	if (!game->map.map)
	{
		free(game);
		return (1);
	}
	reduce_main(game);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 2 || check_file_synthax(argv[1]) == 1)
	{
		ft_printf("Error\ninvalid file\n");
		return (1);
	}
	if (reduce_main_bis(argv) == 1)
		return (1);
	return (0);
}
