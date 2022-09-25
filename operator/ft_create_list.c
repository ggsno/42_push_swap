/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go <go@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:21:12 by go                #+#    #+#             */
/*   Updated: 2022/09/25 18:06:50 by go               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

t_list *ft_create_list(int argc, char **argv)
{
	int 	i;
    t_list	*list;
	t_list	*temp;

	i = 1;
	list = ft_lstnew(argv[i++]);
	while (i < argc)
	{
		temp = ft_lstnew(argv[i]);
		ft_lstadd_front(&list, temp);
		i++;
	}
    
    return list;
}