/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go <go@student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:57:47 by go                #+#    #+#             */
/*   Updated: 2022/03/13 21:09:03 by go               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_i;
	size_t	src_i;

	dst_i = 0;
	src_i = 0;
	while (dst[dst_i] && dst_i < dstsize)
		dst_i++;
	while (src[src_i] && (dst_i + src_i + 1) < dstsize)
	{
		dst[dst_i + src_i] = src[src_i];
		src_i++;
	}
	if (dst_i < dstsize)
		dst[dst_i + src_i] = '\0';
	src_i = 0;
	while (src[src_i])
		src_i++;
	return (dst_i + src_i);
}
