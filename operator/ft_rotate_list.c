/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go <go@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:23:45 by go                #+#    #+#             */
/*   Updated: 2022/09/29 10:06:48 by go               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

int	ft_ra(t_list **list_a, int is_print)
{
	t_list	*will_be_head;

	if (!(*list_a) || !((*list_a)->n))
		return (0);
	will_be_head = (*list_a)->n;
	ft_lstlast(*list_a)->n = *list_a;
	(*list_a)->n = NULL;
	*list_a = will_be_head;
	if (is_print == 1)
		ft_putstr("ra\n");
	return (1);
}

int	ft_rb(t_list **list_b, int is_print)
{
	t_list	*will_be_head;

	if (!(*list_b) || !((*list_b)->n))
		return (0);
	will_be_head = (*list_b)->n;
	ft_lstlast(*list_b)->n = *list_b;
	(*list_b)->n = NULL;
	*list_b = will_be_head;
	if (is_print == 1)
		ft_putstr("rb\n");
	return (1);
}

int	ft_rr(t_list **list_a, t_list **list_b)
{
	if (!ft_ra(list_a, 0) || !ft_rb(list_b, 0))
		return (0);
	ft_putstr("rr\n");
	return (1);
}
