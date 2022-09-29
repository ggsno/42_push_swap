/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go <go@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:32:35 by go                #+#    #+#             */
/*   Updated: 2022/09/29 14:35:58 by go               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*ptr;
	t_list	*next;

	ptr = *lst;
	while (ptr)
	{
		next = ptr->next;
        free(ptr);
		ptr = next;
	}
	*lst = NULL;
}

