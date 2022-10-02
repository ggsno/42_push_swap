/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go <go@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:21:12 by go                #+#    #+#             */
/*   Updated: 2022/10/02 17:04:45 by go               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

int	has_duplicate(t_list *list)
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

static int	has_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

static void	ppap(char **dance, t_list **list, int i, int is_dynamic_dance)
{
	if (!ft_is_valid_letter(dance[i]))
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

static void	do_space(char **argv, t_list **list, int i)
{
	char	**temp;
	int		j;

	temp = ft_split(argv[i], ' ');
	if (!temp || !temp[0])
		ft_print_error_exit(1);
	j = -1;
	while (temp[++j])
		ppap(temp, list, j, 1);
	ft_allfree(temp);
}

void	*ft_set_list(int argc, char **argv, t_list **list)
{
	int		i;

	i = 0;
	while (++i < argc)
	{
		if (has_space(argv[i]))
			do_space(argv, list, i);
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
