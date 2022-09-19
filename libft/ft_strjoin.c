/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go <go@student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 12:44:17 by go                #+#    #+#             */
/*   Updated: 2022/03/12 11:27:04 by go               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	r_i;
	size_t	s_i;

	result = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!result)
		return (NULL);
	r_i = 0;
	s_i = 0;
	while (s1[s_i])
		result[r_i++] = s1[s_i++];
	s_i = 0;
	while (s2[s_i])
		result[r_i++] = s2[s_i++];
	result[r_i] = '\0';
	return (result);
}
