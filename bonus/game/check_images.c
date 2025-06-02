/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_images.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolens <lbolens@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:45:58 by lbolens           #+#    #+#             */
/*   Updated: 2025/06/02 14:25:36 by lbolens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	check_images_map(t_game *game)
{
	if (!game->images.img_wall || !game->images.img_collectible
		|| !game->images.img_floor || !game->images.img_exit
		|| !game->images.img_1x1 || !game->images.img_asteroid)
	{
		ft_printf("Error\nFailed to load an image in map\n");
		destroy_game(game);
		exit(1);
	}
}

void	check_images_player(t_game *game)
{
	if (!game->images.img_player_down || !game->images.img_player_left
		|| !game->images.img_player_right || !game->images.img_player_up)
	{
		ft_printf("Error\nFailed to load an image in player\n");
		destroy_game(game);
		exit(1);
	}
}

void	check_images_moves(t_game *game)
{
	if (!game->images.img_m || !game->images.img_o || !game->images.img_v
		|| !game->images.img_e || !game->images.img_s
		|| !game->images.img_points)
	{
		ft_printf("Error\nFailed to load an image in moves\n");
		destroy_game(game);
		exit(1);
	}
}

void	check_images_digits(t_game *game)
{
	if (!game->images.img_0 || !game->images.img_1 || !game->images.img_2
		|| !game->images.img_3 || !game->images.img_4)
	{
		ft_printf("Error\nFailed to load an image in digits\n");
		destroy_game(game);
		exit(1);
	}
}

void	check_images_digits_bis(t_game *game)
{
	if (!game->images.img_5 || !game->images.img_6 || !game->images.img_7
		|| !game->images.img_8 || !game->images.img_9)
	{
		ft_printf("Error\nFailed to load an image in digits\n");
		destroy_game(game);
		exit(1);
	}
}
