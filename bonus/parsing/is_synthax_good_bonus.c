/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_synthax_good_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolens <lbolens@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:28:58 by lbolens           #+#    #+#             */
/*   Updated: 2025/06/02 14:53:07 by lbolens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "../so_long_bonus.h"

int	check_synthax(char **map, int nbr_p, int nbr_c, int nbr_e)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'P'
				&& map[i][j] != 'C' && map[i][j] != 'E' && map[i][j] != '\n')
				return (0);
			if (map[i][j] == 'P')
				nbr_p++;
			else if (map[i][j] == 'C')
				nbr_c++;
			else if (map[i][j] == 'E')
				nbr_e++;
			j++;
		}
		i++;
	}
	if ((nbr_p != 1) || (nbr_c < 1) || (nbr_e != 1))
		return (0);
	return (1);
}
