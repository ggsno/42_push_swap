/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go <go@student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:02:36 by go                #+#    #+#             */
/*   Updated: 2022/03/13 12:29:51 by go               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_find_addr(const char *str, const char *ndl, size_t i, int *flag)
{
	const size_t	origin_index = i;
	size_t			target_index;

	*flag = 1;
	target_index = 0;
	while (ndl[target_index] != '\0')
	{
		if (str[i] == '\0')
			return (0);
		if (str[i++] != ndl[target_index++])
		{
			*flag = 0;
			break ;
		}
	}
	if (*flag)
		return ((char *)(str + origin_index));
	return ((char *)str);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const size_t	needle_size = ft_strlen(needle);
	size_t			i;
	char			*found_addr;
	int				is_found;

	if (needle_size == 0)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0' && i + needle_size <= len)
	{
		found_addr = ft_find_addr(haystack, needle, i, &is_found);
		if (is_found)
			return (found_addr);
		if (found_addr == 0)
			return (0);
		i++;
	}
	return (0);
}
