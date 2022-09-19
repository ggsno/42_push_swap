/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go <go@student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:19:41 by go                #+#    #+#             */
/*   Updated: 2022/03/11 17:38:51 by go               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	ft_putnbr(int n)
{
	char	number[10];
	int		i;
	int		rt_size;

	i = 0;
	rt_size = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		rt_size++;
	}
	while (n || i == 0)
	{
		number[i++] = ft_abs(n % 10) + '0';
		n /= 10;
	}
	rt_size += i;
	while (i--)
		write(1, &number[i], 1);
	return (rt_size);
}
