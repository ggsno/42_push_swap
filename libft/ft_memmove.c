/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go <go@student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 10:17:07 by go                #+#    #+#             */
/*   Updated: 2022/03/13 18:00:56 by go               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (len == 0 || (!dst && !src))
		return (dst);
	if (dst <= src)
	{
		i = 0;
		while (i != len / sizeof(*dst))
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
	}
	else
	{
		i = len / sizeof(*dst) - 1;
		while (i != 0)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i--;
		}
		((char *)dst)[i] = ((char *)src)[i];
	}
	return (dst);
}
