/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go <go@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 20:20:43 by go                #+#    #+#             */
/*   Updated: 2022/09/29 10:06:48 by go               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*result;

	result = lst;
	if (!result)
		return (NULL);
	while (result->n)
		result = result->n;
	return (result);
}
