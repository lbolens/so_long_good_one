/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolens <lbolens@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:09:17 by lbolens           #+#    #+#             */
/*   Updated: 2025/06/02 13:20:34 by lbolens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "../so_long.h"

static void	render_p(t_game *game, int i, int j)
{
	if (game->player.moves == 0)
		mlx_put_image_to_window(game->mlx, game->window,
			game->images.img_player_down, j * TILE_SIZE, i * TILE_SIZE);
	else if (game->player.y < game->player.last_y)
		mlx_put_image_to_window(game->mlx, game->window,
			game->images.img_player_up, j * TILE_SIZE, i * TILE_SIZE);
	else if (game->player.y > game->player.last_y)
		mlx_put_image_to_window(game->mlx, game->window,
			game->images.img_player_down, j * TILE_SIZE, i * TILE_SIZE);
	else if (game->player.x > game->player.last_x)
		mlx_put_image_to_window(game->mlx, game->window,
			game->images.img_player_right, j * TILE_SIZE, i * TILE_SIZE);
	else if (game->player.x < game->player.last_x)
		mlx_put_image_to_window(game->mlx, game->window,
			game->images.img_player_left, j * TILE_SIZE, i * TILE_SIZE);
	else
		mlx_put_image_to_window(game->mlx, game->window,
			game->images.img_player_down, j * TILE_SIZE, i * TILE_SIZE);
}

static void	render_1(t_game *game, int i, int j)
{
	mlx_put_image_to_window(game->mlx, game->window, game->images.img_wall,
		j * TILE_SIZE, i * TILE_SIZE);
}

void	doing_render(t_game *game, char **map, int i, int j)
{
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				render_1(game, i, j);
			else if (map[i][j] == '0')
				mlx_put_image_to_window(game->mlx, game->window,
					game->images.img_floor, j * TILE_SIZE, i * TILE_SIZE);
			else if (map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->window,
					game->images.img_collectible, j * TILE_SIZE, i * TILE_SIZE);
			else if (map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->window,
					game->images.img_exit, j * TILE_SIZE, i * TILE_SIZE);
			else if (map[i][j] == 'P')
				render_p(game, i, j);
			j++;
		}
		i++;
	}
}
