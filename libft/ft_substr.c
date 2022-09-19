/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go <go@student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 12:18:29 by go                #+#    #+#             */
/*   Updated: 2022/03/13 16:36:26 by go               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
