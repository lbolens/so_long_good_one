/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbolens <lbolens@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:11:43 by lucasbolens       #+#    #+#             */
/*   Updated: 2025/04/11 12:17:21 by lbolens          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *sentence, ...);
int	ft_putchar_printf(char c);
int	ft_putstr_printf(char *s);
int	ft_putnbr_printf(int n);
int	ft_put_unsigned_dec_10(unsigned int n);
int	ft_put_hex_low(unsigned int n);
int	ft_put_hex_up(unsigned int n);
int	ft_put_pointer(void *ptr);

#endif