/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolens <lbolens@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:46:02 by lucasbolens       #+#    #+#             */
/*   Updated: 2025/04/17 13:36:17 by lbolens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_size_p(unsigned long num)
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

static int	ft_put_hex_low_p(unsigned long n)
{
	char	*base;
	char	c;
	int		count;

	base = "0123456789abcdef";
	count = ft_size_p(n);
	if (n >= 16)
		ft_put_hex_low_p(n / 16);
	c = base[n % 16];
	write(1, &c, 1);
	return (count);
}

int	ft_put_pointer(void *ptr)
{
	int		count;

	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		count = 5;
		return (count);
	}
	count = 0;
	write(1, "0x", 2);
	count += 2;
	count += ft_put_hex_low_p((unsigned long)ptr);
	return (count);
}
