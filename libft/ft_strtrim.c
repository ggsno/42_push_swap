/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go <go@student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 12:54:36 by go                #+#    #+#             */
/*   Updated: 2022/03/13 15:40:36 by go               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strchridx(char const *str, char const *set
	, int sign, size_t start)
{
	size_t	result;
	size_t	i;

	if (sign == 1)
		result = 0;
	else
		result = ft_strlen(str) - 1;
	while ((sign == 1 && str[result]) || (sign == -1 && start < result))
	{
		i = 0;
		while (i < ft_strlen(set))
		{
			if (str[result] == set[i])
				i = ft_strlen(set) + 1;
			i++;
		}
		if (i == ft_strlen(set))
			break ;
		result += sign;
	}
	return (result);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	start;
	size_t	end;
	size_t	i;

	start = ft_strchridx(s1, set, 1, 0);
	if (ft_strlen(s1) <= start)
	{
		result = (char *)malloc(sizeof(char));
		if (!result)
			return (NULL);
		result[0] = '\0';
		return (result);
	}
	end = ft_strchridx(s1, set, -1, start);
	result = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!result)
		return (NULL);
	i = 0;
	while (start <= end)
		result[i++] = s1[start++];
	result[i] = '\0';
	return (result);
}
