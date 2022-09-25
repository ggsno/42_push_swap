/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go <go@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:21:12 by go                #+#    #+#             */
/*   Updated: 2022/09/25 22:00:30 by go               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

t_list	*ft_create_list(int argc, char **argv)
{
	int		i;
	t_list	*list;

	i = 1;
	list = ft_lstnew(ft_atoi(argv[i++]));
	while (i < argc)
		ft_lstlast(list)->next = ft_lstnew(ft_atoi(argv[i++]));
	return (list);
}
