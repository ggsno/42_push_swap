/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go <go@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 06:15:52 by go                #+#    #+#             */
/*   Updated: 2022/09/28 07:26:48 by go               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	set_pivot(t_list **list_a, t_list **list_b, \
	int *pivot_small, int *pivot_big)
{
	t_list	*first_node;

	first_node = *list_a;
	if (first_node->content > first_node->next->content)
	{
		*pivot_big = first_node->content;
		*pivot_small = first_node->next->content;
		ft_ra(list_a, 1);
		ft_pb(list_a, list_b);
	}
	else
	{
		*pivot_big = first_node->next->content;
		*pivot_small = first_node->content;
		ft_pb(list_a, list_b);
		ft_ra(list_a, 1);
	}
}

static void	ft_optimize_stack(t_list **list_a, t_list **list_b)
{
	int	pivot_big;
	int	pivot_small;
	int	i;
	int	big_group_size;

	set_pivot(list_a, list_b, &pivot_big, &pivot_small);
	big_group_size = 1;
	i = ft_lstsize(*list_a) - 1;
	while (i-- > 0)
	{
		if ((*list_a)->content > pivot_big)
		{
			ft_ra(list_a, 1);
			big_group_size++;
		}
		else if ((*list_a)->content > pivot_small)
			ft_pb(list_a, list_b);
		else
		{
			ft_pb(list_a, list_b);
			ft_rb(list_b, 1);
		}
	}
	while (big_group_size--)
		ft_pb(list_a, list_b);
}

void	ft_sort(t_list **list_a, t_list **list_b)
{
	int	i;

	i = ft_lstsize(*list_a);
	ft_optimize_stack(list_a, list_b);
}
