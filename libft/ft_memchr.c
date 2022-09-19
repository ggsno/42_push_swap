/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go <go@student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 19:45:39 by go                #+#    #+#             */
/*   Updated: 2022/03/14 19:13:17 by go               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	cmp;
	size_t			i;

	str = (unsigned char *)s;
	cmp = (unsigned char)c;
	if (!n)
		return (NULL);
	i = 0;
	while (i < n)
	{
		if (str[i] == cmp)
			return (str + i);
		i++;
	}
	if (i < n && cmp == '\0')
		return (str + i);
	return (NULL);
}
