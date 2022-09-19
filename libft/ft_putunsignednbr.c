/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsignednbr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go <go@student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:19:19 by go                #+#    #+#             */
/*   Updated: 2022/09/20 00:32:32 by go               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	ft_putunsignednbr(unsigned int n)
{
	char	number[10];
	int		i;
	int		rt_size;

	i = 0;
	while (n || i == 0)
	{
		number[i++] = (n % 10) + '0';
		n /= 10;
	}
	rt_size = i;
	while (i--)
		write(1, &number[i], 1);
	return (rt_size);
}
