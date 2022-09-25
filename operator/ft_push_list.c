/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go <go@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:11:17 by go                #+#    #+#             */
/*   Updated: 2022/09/25 19:05:32 by go               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

int	ft_pa(t_list **list_a, t_list **list_b)
{
	t_list	*temp;

	if (!(*list_b))
		return (0);
	temp = *list_b;
	*list_b = (*list_b)->next;
	temp->next = *list_a;
	*list_a = temp;
	ft_putstr("pa\n");
	return (1);
}

int	ft_pb(t_list **list_a, t_list **list_b)
{
	t_list	*temp;

	if (!(*list_a))
		return (0);
	temp = *list_a;
	*list_a = (*list_a)->next;
	temp->next = *list_b;
	*list_b = temp;
	ft_putstr("pb\n");
	return (1);
}
