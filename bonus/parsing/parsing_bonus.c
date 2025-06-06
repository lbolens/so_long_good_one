/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolens <lbolens@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:23:29 by lbolens           #+#    #+#             */
/*   Updated: 2025/06/02 14:59:35 by lbolens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "../so_long_bonus.h"

static int	validate_map(char **map)
{
	int	screen_width;
	int	screen_height;

	if (is_rectangle(map) == 0 || check_synthax(map, 0, 0, 0) == 0
		|| (is_walls(map, 0, number_lines(map), number_columns(map[0])) == 0)
		|| (is_map_solvable(map, -1, -1, number_lines(map)) == 0))
	{
		ft_printf("Error\nInvalid map\n");
		return (0);
	}
	screen_width = 3840;
	screen_height = 2160;
	if (number_columns(map[0]) * TILE_SIZE > screen_width || number_lines(map)
		* TILE_SIZE > screen_height)
	{
		ft_printf("Error\nmap exceeds screen size\n");
		return (0);
	}
	return (1);
}

static char	**load_map(int fd, int i)
{
	char	**map;

	map = (char **)malloc(1024 * sizeof(char *));
	if (!map)
		return (NULL);
	map[i] = get_next_line(fd);
	while (map[i] != NULL)
	{
		i++;
		map[i] = get_next_line(fd);
	}
	if (i == 0)
	{
		free(map);
		ft_printf("Error\nEmpty map\n");
		return (NULL);
	}
	map[i] = NULL;
	return (map);
}

char	**is_map_valid(char *filepath, int fd, int i)
{
	char	**map;

	if (!filepath)
		return (NULL);
	fd = open(filepath, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nCannot open file\n");
		return (NULL);
	}
	map = load_map(fd, i);
	close(fd);
	if (!map)
		return (NULL);
	if (validate_map(map) == 0)
	{
		free_map(map);
		return (NULL);
	}
	return (map);
}
