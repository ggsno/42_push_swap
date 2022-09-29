/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go <go@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:21:12 by go                #+#    #+#             */
/*   Updated: 2022/09/29 17:31:39 by go               ###   ########.fr       */
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

static int	is_valid_letter(const char *str)
{
	int	sign;
	int	result;
	size_t	i;

	sign = 1;
	result = 0;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] && '0' <= str[i] && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	if (ft_strlen(str) > i)
		return (0);
	return (1);
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
			{
				if (!is_valid_letter(temp[j]))
				{
					ft_lstclear(list);
					free(temp);
					ft_putstr("Error\n");
					exit(1);
				}
				if (*list)
					ft_lstlast(*list)->n = ft_lstnew(ft_atoi(temp[j]));
				else
					*list = ft_lstnew(ft_atoi(temp[j]));
			}
			free(temp);
		}
		else
		{
			if (!is_valid_letter(argv[i]))
				{
					ft_lstclear(list);
					free(temp);
					ft_putstr("Error\n");
					exit(1);
				}
			if (*list)
				ft_lstlast(*list)->n = ft_lstnew(ft_atoi(argv[i]));
			else
				*list = ft_lstnew(ft_atoi(argv[i]));
		}
	}
	return (list);
}
