/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolens <lbolens@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:18:04 by lbolens           #+#    #+#             */
/*   Updated: 2025/05/30 14:18:05 by lbolens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

void	init_game(t_game *game, char **map)
{
	game->map.map_height = number_lines(map);
	game->map.map_width = number_columns(map[0]);
	game->player.x = -1;
	game->player.y = -1;
	game->player.last_x = -1;
	game->player.last_y = -1;
	find_player_position(map, &game->player.x, &game->player.y);
	game->map.total_collectibles = number_collectibles(map);
	game->player.collected = 0;
	game->player.moves = 0;
	game->asteroid = NULL;
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		printf("Error: Failed to initialize MLX\n");
		exit(1);
	}
	init_images(game);
}

int	game_loop(t_game *game)
{
	render_map(game, 0, 0);
	return (0);
}
