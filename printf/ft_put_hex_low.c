/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex_low.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolens <lbolens@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:43:20 by lucasbolens       #+#    #+#             */
/*   Updated: 2025/04/17 13:36:37 by lbolens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_size(unsigned int num)
{
	int				size;
	unsigned long	n;

	size = 0;
	n = num;
	while (n >= 16)
	{
		n = n / 16;
		size++;
	}
	size++;
	return (size);
}

int	ft_put_hex_low(unsigned int n)
{
	char	*base;
	char	c;
	int		count;

	base = "0123456789abcdef";
	count = ft_size(n);
	if (n >= 16)
		ft_put_hex_low(n / 16);
	c = base[n % 16];
	write(1, &c, 1);
	return (count);
}
