/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go <go@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 20:20:43 by go                #+#    #+#             */
/*   Updated: 2022/09/25 21:57:46 by go               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*result;

	result = lst;
	if (!result)
		return (NULL);
	while (result->next)
		result = result->next;
	return (result);
}
