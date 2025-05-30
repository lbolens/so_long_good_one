/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_dec_10.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolens <lbolens@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:45:52 by lucasbolens       #+#    #+#             */
/*   Updated: 2025/04/17 13:36:59 by lbolens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_size_unsigned(unsigned int num)
{
	int	size;

	size = 0;
	while (num >= 10)
	{
		num = num / 10;
		size++;
	}
	size++;
	return (size);
}

int	ft_put_unsigned_dec_10(unsigned int n)
{
	char	c;
	int		count;

	count = ft_size_unsigned(n);
	if (n >= 10)
		ft_put_unsigned_dec_10(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
	return (count);
}
