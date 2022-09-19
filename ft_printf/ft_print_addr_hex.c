/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_addr_hex.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go <go@student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:27:44 by go                #+#    #+#             */
/*   Updated: 2022/06/27 16:12:21 by go               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_print_addr_hex(void *arg)
{
	unsigned long long	addr;
	char				str[16];
	int					length;
	int					i;

	addr = (unsigned long long)arg;
	i = 0;
	while (i == 0 || addr)
	{
		if (addr % 16 >= 10)
			str[i++] = addr % 16 - 10 + 'a';
		else
			str[i++] = addr % 16 + '0';
		addr /= 16;
	}
	length = i;
	write(1, "0x", 2);
	while (i--)
		write(1, &str[i], 1);
	return (length + 2);
}
