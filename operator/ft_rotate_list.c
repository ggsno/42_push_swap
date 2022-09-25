/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go <go@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:23:45 by go                #+#    #+#             */
/*   Updated: 2022/09/25 19:05:05 by go               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

int	ft_ra(t_list **list_a, int is_print)
{
	t_list	*temp;
	t_list	*cp;

	if (!(*list_a) || !((*list_a)->next))
		return (0);
	temp = *list_a;
	cp = (*list_a)->next;
	while ((*list_a)->next)
		*list_a = (*list_a)->next;
	(*list_a)->next = temp;
	temp->next = NULL;
	*list_a = cp;
    if(is_print == 1)
	    ft_putstr("ra\n");
    return (1);
}

int	ft_rb(t_list **list_b, int is_print)
{
	t_list	*temp;
	t_list	*cp;

	if (!(*list_b) || !(*list_b)->next)
		return (0);
	temp = *list_b;
	cp = (*list_b)->next;
	while ((*list_b)->next)
		*list_b = (*list_b)->next;
	(*list_b)->next = temp;
	temp->next = NULL;
	*list_b = cp;
	if(is_print == 1)
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
