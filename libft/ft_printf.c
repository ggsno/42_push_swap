/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go <go@student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:19:48 by go                #+#    #+#             */
/*   Updated: 2022/05/02 16:35:58 by go               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_format(char format, va_list ap)
{
	int	rt_size;

	rt_size = 0;
	if (format == 'c')
		rt_size += ft_putchar((char)va_arg(ap, int));
	else if (format == 's')
		rt_size += ft_putstr(va_arg(ap, char *));
	else if (format == 'p')
		rt_size += ft_print_addr_hex(va_arg(ap, void *));
	else if (format == 'd' || format == 'i')
		rt_size += ft_putnbr(va_arg(ap, int));
	else if (format == 'u')
		rt_size += ft_putunsignednbr(va_arg(ap, uint64_t));
	else if (format == 'x')
		rt_size += ft_putnbr_base(va_arg(ap, uint64_t), "0123456789abcdef");
	else if (format == 'X')
		rt_size += ft_putnbr_base(va_arg(ap, uint64_t), "0123456789ABCDEF");
	else if (format == '%')
		rt_size += write(1, "%", 1);
	else
		return (-1);
	return (rt_size);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	i;
	int		rt_size;

	va_start(ap, format);
	i = 0;
	rt_size = 0;
	while (i < ft_strlen(format))
	{
		if (format[i] == '%')
			rt_size += ft_print_format(format[++i], ap);
		else
		{
			write(1, format + i, 1);
			rt_size++;
		}
		i++;
	}
	va_end(ap);
	return (rt_size);
}
