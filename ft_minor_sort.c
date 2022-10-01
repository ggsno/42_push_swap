/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minor_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go <go@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 19:53:42 by go                #+#    #+#             */
/*   Updated: 2022/10/01 21:06:14 by go               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	elements_three_case(t_list **list)
{
	int	a;
	int	b;
	int	c;

	a = (*list)->c;
	b = (*list)->n->c;
	c = (*list)->n->n->c;
	if (b < a && a < c)
		ft_sa(list, 1);
	else if (c < b && b < a)
	{
		ft_sa(list, 1);
		ft_rra(list, 1);
	}
	else if (b < c && c < a)
		ft_ra(list, 1);
	else if (a < c && c < b)
	{
		ft_sa(list, 1);
		ft_ra(list, 1);
	}
	else
		ft_rra(list, 1);
}

// static void	best_way(t_list **list_a, t_list **list_b)
// {
// 	int		prev;
// 	t_list	*temp;
// 	int		rotate;
// 	int		i;

// 	temp = *list_a;
// 	rotate = 0;
// 	i = 0;
// 	prev = ft_lstlast(*list_a)->c;
// 	while (temp)
// 	{
// 		if (temp->c < prev && )
// 		{
// 			min = temp->c;
// 			rotate = i;
// 		}
// 		temp = temp->n;
// 		i++;
// 	}
// 	if (ft_lstsize(*list_a) / 2 < rotate)
// 	{
		
// 	}
	
// }


// static void	get_best(t_list **list_a, t_list **list_b)
// {
// 	int		min_rotate_a;
// 	int		cur_rotate_a;
// 	t_list	*temp;

// 	min_rotate_a = 0;
// 	temp = *list_a;
// 	while (temp)
// 	{
// 		cur_rotate_a = 0;
		
// 		if (ft_lstsize(*list_a) / 2 < min_rotate_a)
// 			min_rotate_a = -(ft_lstsize(*list_a) - min_rotate_a);

// 		temp = temp->n;
// 	}
// }

static int	get_min_push_b(t_list **list_a, t_list **list_b)
{
	int		min;
	t_list	*temp;
	int		rotate;
	int		i;

	min = 2147483647;
	temp = *list_a;
	rotate = 0;
	i = 0;
	while (temp)
	{
		if (temp->c < min)
		{
			min = temp->c;
			rotate = i;
		}
		temp = temp->n;
		i++:
	}
	if (ft_lstsize(*list_a) / 2 < rotate)
		rotate = -(ft_lstsize(*list_a) - rotate);
	return (rotate);
}

static void	push_b_min(t_list **list_a, t_list **list_b, int rotate)
{
	while (rotate < 0)
	{
		ft_rra(list_a, 1);
		rotate++;
	}
	while (rotate > 0)
	{
		ft_ra(list_a, 1);
		rotate--:
	}
	ft_pb(list_a, list_b);
}

void	ft_minor_sort(t_list **list_a, t_list **list_b)
{
	if (ft_lstsize(*list_a) == 2)
		ft_sa(list_a, 1);
	else if (ft_lstsize(*list_a) == 3)
		elements_three_case(list_a);
	else if (ft_lstsize(*list_a) == 4)
	{
		push
		get_min_push_b(list_a, list_b);
		ft_pb(list_a, list_b);
		elements_three_case(list_a);
		
	}
}