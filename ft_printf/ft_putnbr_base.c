/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go <go@student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:18:56 by go                #+#    #+#             */
/*   Updated: 2022/06/27 16:19:06 by go               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

static int	print_n_notation(unsigned int decimal, char *base, int base_number)
{
	int	n_notation_arr[32];
	int	i;
	int	rt_size;

	rt_size = 0;
	i = 0;
	while (i == 0 || decimal)
	{
		n_notation_arr[i++] = decimal % base_number;
		decimal /= base_number;
	}
	while (--i >= 0)
	{
		write(1, &base[n_notation_arr[i]], 1);
		rt_size++;
	}
	return (rt_size);
}

int	ft_putnbr_base(unsigned int nbr, char *base)
{
	int		base_number;

	base_number = ft_strlen(base);
	return (print_n_notation(nbr, base, base_number));
}
