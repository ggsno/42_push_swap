/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go <go@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:21:12 by go                #+#    #+#             */
/*   Updated: 2022/09/29 15:21:23 by go               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

static int	has_space(char* str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

void	*ft_set_list(int argc, char **argv, t_list** list)
{
	int		i;
	int		j;
	char	**temp;

	i = 0;
	while (++i < argc)
	{
		if (has_space(argv[i]))
		{
			temp = ft_split(argv[i], ' ');
			j = -1;
			while (temp[++j])
				if (*list)
					ft_lstlast(*list)->n = ft_lstnew(ft_atoi(temp[j]));
				else
					*list = ft_lstnew(ft_atoi(temp[j]));
			free(temp);
		}
		else
			if (*list)
				ft_lstlast(*list)->n = ft_lstnew(ft_atoi(argv[i]));
			else
				*list = ft_lstnew(ft_atoi(argv[i]));
	}
	return (list);
}
