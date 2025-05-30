/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolens <lbolens@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:46:46 by lucasbolens       #+#    #+#             */
/*   Updated: 2025/04/16 12:17:07 by lbolens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_printf(char *s)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (!s)
		s = "(null)";
	while (s[i] != 0)
	{
		write(1, &s[i], 1);
		i++;
		count++;
	}
	return (count);
}
