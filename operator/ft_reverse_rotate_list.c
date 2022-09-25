/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go <go@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:23:45 by go                #+#    #+#             */
/*   Updated: 2022/09/25 21:12:12 by go               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

int	ft_rra(t_list **list_a, int is_print)
{
	t_list	*will_be_tail;
	t_list	*will_be_second;

	if (!(*list_a) || !((*list_a)->next))
		return (0);
	will_be_tail = *list_a;
	while (will_be_tail->next->next)
		will_be_tail = will_be_tail->next;
	will_be_second = *list_a;
	*list_a = ft_lstlast(*list_a);
	(*list_a)->next = will_be_second;
	will_be_tail->next = NULL;
	if (is_print == 1)
		ft_putstr("rra\n");
	return (1);
}

int	ft_rrb(t_list **list_b, int is_print)
{
	t_list	*will_be_tail;
	t_list	*will_be_second;

	if (!(*list_b) || !((*list_b)->next))
		return (0);
	will_be_tail = *list_b;
	while (will_be_tail->next->next)
		will_be_tail = will_be_tail->next;
	will_be_second = *list_b;
	*list_b = ft_lstlast(*list_b);
	(*list_b)->next = will_be_second;
	will_be_tail->next = NULL;
	if (is_print == 1)
		ft_putstr("rra\n");
	return (1);
}

int	ft_rrr(t_list **list_a, t_list **list_b)
{
	if (!ft_rra(list_a, 0) || !ft_rrb(list_b, 0))
		return (0);
	ft_putstr("rrr\n");
	return (1);
}
