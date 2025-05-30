/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex_up.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolens <lbolens@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:46:06 by lucasbolens       #+#    #+#             */
/*   Updated: 2025/04/17 13:36:43 by lbolens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex_size(unsigned int num)
{
	int	size;

	size = 0;
	while (num >= 16)
	{
		num = num / 16;
		size++;
	}
	size++;
	return (size);
}

int	ft_put_hex_up(unsigned int n)
{
	char	*base;
	char	c;
	int		count;

	base = "0123456789ABCDEF";
	count = ft_hex_size(n);
	if (n >= 16)
		ft_put_hex_up(n / 16);
	c = base[n % 16];
	write(1, &c, 1);
	return (count);
}
