/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_quater.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolens <lbolens@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:08:57 by lbolens           #+#    #+#             */
/*   Updated: 2025/05/30 14:16:23 by lbolens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

void	render_map(t_game *game, int i, int j)
{
	char	**map;

	map = game->map.map;
	doing_render(game, map, i, j);
}
