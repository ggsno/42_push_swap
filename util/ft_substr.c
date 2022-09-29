/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go <go@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:00:31 by go                #+#    #+#             */
/*   Updated: 2022/09/29 15:02:07 by go               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

static void	ft_bzero(void *s, size_t n)
{
	while (n--)
		*((char *)s + n) = 0;
}

static void	*ft_calloc(size_t count, size_t size)
{
	char	*result;

	result = malloc(size * count);
	if (!result)
		return (NULL);
	ft_bzero(result, size * count);
	return (result);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;
	size_t	result_len;

	if (ft_strlen(s) <= start)
		return (ft_calloc(1, 1));
	if (ft_strlen(s) - (size_t)start < len)
		result_len = ft_strlen(s) - (size_t)start;
	else
		result_len = len;
	result = (char *)malloc(sizeof(char) * (result_len + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < result_len)
		result[i++] = s[start++];
	result[i] = '\0';
	return (result);
}
