/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolens <lbolens@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:19:29 by lbolens           #+#    #+#             */
/*   Updated: 2025/06/02 14:22:10 by lbolens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "mlx.h"

static void	init_map_images(t_game *game, int w, int h)
{
	w = TILE_SIZE;
	h = TILE_SIZE;
	game->images.img_wall = NULL;
	game->images.img_collectible = NULL;
	game->images.img_floor = NULL;
	game->images.img_exit = NULL;
	game->images.img_floor = mlx_xpm_file_to_image(game->mlx,
			"textures/tuile_floor.xpm", &w, &h);
	game->images.img_wall = mlx_xpm_file_to_image(game->mlx,
			"textures/tuile_wall.xpm", &w, &h);
	game->images.img_collectible = mlx_xpm_file_to_image(game->mlx,
			"textures/tuile_collectible.xpm", &w, &h);
	game->images.img_exit = mlx_xpm_file_to_image(game->mlx,
			"textures/tuile_exit.xpm", &w, &h);
	if (!game->images.img_collectible || !game->images.img_wall
		|| !game->images.img_floor || !game->images.img_exit)
	{
		ft_printf("Error\nFailed to log an image in map\n");
		destroy_game(game);
		exit(1);
	}
}

static void	init_player_images(t_game *game)
{
	int	w;
	int	h;

	w = TILE_SIZE;
	h = TILE_SIZE;
	game->images.img_player_up = NULL;
	game->images.img_player_down = NULL;
	game->images.img_player_left = NULL;
	game->images.img_player_right = NULL;
	game->images.img_player_up = mlx_xpm_file_to_image(game->mlx,
			"textures/tuile_player_up.xpm", &w, &h);
	game->images.img_player_down = mlx_xpm_file_to_image(game->mlx,
			"textures/tuile_player_down.xpm", &w, &h);
	game->images.img_player_left = mlx_xpm_file_to_image(game->mlx,
			"textures/tuile_player_left.xpm", &w, &h);
	game->images.img_player_right = mlx_xpm_file_to_image(game->mlx,
			"textures/tuile_player_right.xpm", &w, &h);
	if (!game->images.img_player_up || !game->images.img_player_down
		|| !game->images.img_player_right || !game->images.img_player_left)
	{
		ft_printf("Error\nFailed to log an image in player\n");
		destroy_game(game);
		exit(1);
	}
}

void	init_images(t_game *game)
{
	if (!game || !game->mlx)
		return ;
	init_map_images(game, 0, 0);
	init_player_images(game);
}
