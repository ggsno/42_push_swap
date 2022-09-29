/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go <go@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:31:44 by go                #+#    #+#             */
/*   Updated: 2022/09/29 14:36:21 by go               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(int))
{
	t_list	*result;
	t_list	*newone;

	result = NULL;
	while (lst)
	{
		newone = ft_lstnew(f(lst->content));
		if (!newone)
		{
			ft_lstclear(&result);
			return (NULL);
		}
		ft_lstadd_back(&result, newone);
		lst = lst->next;
	}
	return (result);
}
