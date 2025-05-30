/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_walls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolens <lbolens@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:29:14 by lbolens           #+#    #+#             */
/*   Updated: 2025/05/30 12:29:21 by lbolens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

static int	is_only_one(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] != '1' && map[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

static int	check_between_top_and_bottom(char *map, int nbr_columns)
{
	if (map[0] != '1' || map[nbr_columns - 1] != '1')
		return (0);
	return (1);
}

int	is_walls(char **map, int i, int nbr_lines, int nbr_columns)
{
	while (map[i])
	{
		if (i == 0)
		{
			if (is_only_one(map[i]) == 0)
				return (0);
		}
		else if (i > 0 && i < (nbr_lines - 1))
		{
			if (check_between_top_and_bottom(map[i], nbr_columns) == 0)
				return (0);
		}
		else if (i == (nbr_lines - 1))
		{
			if (is_only_one(map[i]) == 0)
				return (0);
		}
		i++;
	}
	return (1);
}
