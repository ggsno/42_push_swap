/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free_args.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go <go@student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 21:33:02 by go                #+#    #+#             */
/*   Updated: 2022/09/20 00:35:44 by go               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free_args(char *s1, char *s2)
{
	char	*result;
	size_t	r_i;
	size_t	s_i;

	result = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!result)
		return (NULL);
	r_i = 0;
	s_i = 0;
	while (s1 && s1[s_i])
		result[r_i++] = s1[s_i++];
	s_i = 0;
	while (s2 && s2[s_i])
		result[r_i++] = s2[s_i++];
	result[r_i] = '\0';
	if (s1)
		free(s1);
	s1 = NULL;
	if (s2)
		free(s2);
	s2 = NULL;
	return (result);
}
