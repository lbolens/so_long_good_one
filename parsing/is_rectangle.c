/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rectangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolens <lbolens@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:28:42 by lbolens           #+#    #+#             */
/*   Updated: 2025/06/02 13:20:58 by lbolens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "../so_long.h"

int	is_rectangle(char **map)
{
	int	i;

	i = 0;
	while (map[i + 1])
	{
		if (number_columns(map[i]) != number_columns(map[i + 1]))
			return (0);
		i++;
	}
	return (1);
}
