/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go <go@student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:09:19 by go                #+#    #+#             */
/*   Updated: 2022/03/13 21:09:26 by go               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	int		is_null_terminated;

	i = 0;
	is_null_terminated = 0;
	while (src[i] != '\0')
	{
		if (i == dstsize - 1 && dstsize != 0)
		{
			is_null_terminated = 1;
			dst[i] = '\0';
		}
		else if (dstsize != 0 && i < dstsize - 1)
			dst[i] = src[i];
		i++;
	}
	if (is_null_terminated != 1 && dstsize != 0)
		dst[i] = '\0';
	return (i);
}
