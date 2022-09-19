/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go <go@student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:56:23 by go                #+#    #+#             */
/*   Updated: 2022/03/13 18:05:08 by go               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (n == 0 || (!dst && !src))
		return (dst);
	if (dst <= src)
	{
		i = 0;
		while (i != n / sizeof(*dst))
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
	}
	else
	{
		i = n / sizeof(*dst) - 1;
		while (i != 0)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i--;
		}
		((char *)dst)[i] = ((char *)src)[i];
	}
	return (dst);
}
