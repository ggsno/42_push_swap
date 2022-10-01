/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go <go@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:21:12 by go                #+#    #+#             */
/*   Updated: 2022/10/01 19:36:55 by go               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

static int	is_valid_letter(const char *str)
{
	int			sign;
	long long	result;
	size_t		i;

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
	if (ft_strlen(str) > i || result > 2147483647 || result < -2147483648)
		return (0);
	return (1);
}

int has_duplicate(t_list *list)
{
	t_list	*temp;
	int		comp;

	while (list)
	{
		comp = list->c;
		temp = list->n;
		while (temp)
		{
			if (temp->c == comp)
				return (1);
			temp = temp->n;
		}
		list = list->n;
	}
	return (0);
}

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


static void ppap(char **dance, t_list** list, int i, int is_dynamic_dance)
{
	if (!is_valid_letter(dance[i]))
	{
		ft_lstclear(list);
		if (is_dynamic_dance)
			free(dance);
		ft_print_error_exit(1);
	}
	if (*list)
		ft_lstlast(*list)->n = ft_lstnew(ft_atoi(dance[i]));
	else
		*list = ft_lstnew(ft_atoi(dance[i]));
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
				ppap(temp, list, j,1);
			free(temp);
		}
		else
			ppap(argv, list, i, 0);
	}
	if (has_duplicate(*list))
	{
		ft_lstclear(list);
		ft_print_error_exit(1);
	}
	return (list);
}
