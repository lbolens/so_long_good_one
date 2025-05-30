/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolens <lbolens@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:15:32 by lucasbolens       #+#    #+#             */
/*   Updated: 2025/04/17 13:36:30 by lbolens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_format(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar_printf(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr_printf(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_put_pointer(va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_printf(va_arg(args, int)));
	else if (c == 'u')
		return (ft_put_unsigned_dec_10(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_put_hex_low(va_arg(args, unsigned long)));
	else if (c == 'X')
		return (ft_put_hex_up(va_arg(args, unsigned int)));
	else if (c == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *sentence, ...)
{
	int		i;
	int		count;
	va_list	args;

	va_start(args, sentence);
	i = 0;
	count = 0;
	while (sentence[i])
	{
		if (sentence[i] == '%' && sentence[i + 1])
		{
			i++;
			count += ft_handle_format(sentence[i], args);
		}
		else
			count += ft_putchar_printf(sentence[i]);
		i++;
	}
	va_end(args);
	return (count);
}
