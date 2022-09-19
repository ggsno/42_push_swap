/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go <go@student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:33:27 by go                #+#    #+#             */
/*   Updated: 2022/03/25 14:37:54 by go               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_splitedcount(char const *str, char c)
{
	int	i;
	int	is_prev_seperator;
	int	valid_seperate_count;

	if (!ft_strlen(str))
		return (0);
	i = 0;
	is_prev_seperator = 0;
	valid_seperate_count = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			if (!is_prev_seperator && i)
				valid_seperate_count++;
			is_prev_seperator = 1;
		}
		else
			is_prev_seperator = 0;
		i++;
	}
	if (!is_prev_seperator)
		valid_seperate_count++;
	return (valid_seperate_count);
}

void	*ft_allfree(char **lst)
{
	size_t	i;

	i = 0;
	while (lst[i])
	{
		free(lst[i++]);
		lst[i - 1] = NULL;
	}
	free(lst);
	lst = NULL;
	return (NULL);
}

char	**ft_dosplit(char const *str, char **result, size_t count, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;

	k = 0;
	i = 0;
	while (k < count)
	{
		while (str[i] == c)
			i++;
		j = i++;
		while (str[i] && str[i] != c)
			i++;
		result[k] = ft_substr(str, j, i - j);
		if (!result[k])
			return (ft_allfree(result));
		i++;
		k++;
	}
	return (result);
}

char	**ft_split(char const *str, char c)
{
	size_t	count;
	char	**result;

	count = ft_splitedcount(str, c);
	result = (char **)malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (NULL);
	result[count] = NULL;
	return (ft_dosplit(str, result, count, c));
}
