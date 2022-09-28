/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go <go@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 06:15:52 by go                #+#    #+#             */
/*   Updated: 2022/09/28 10:38:37 by go               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_set_better_rotate(int *origin_a, int *origin_b, int new_a, int new_b)
{
	int	origin_cnt;
	int new_cnt;

	origin_cnt = 0;
	new_cnt = 0;
	if ((0 < *origin_a && 0 < *origin_b) || (*origin_a < 0  && *origin_b < 0))
		origin_cnt = ft_get_bigger(ft_abs(*origin_a), ft_abs(*origin_b));
	else
		origin_cnt = ft_abs(*origin_a) + ft_abs(*origin_b);
	if ((0 < new_a && 0 < new_b) || (new_a < 0  && new_b < 0))
		new_cnt = ft_get_bigger(ft_abs(new_a), ft_abs(new_b));
	else
		new_cnt = ft_abs(new_a) + ft_abs(new_b);
	if (new_cnt < origin_cnt)
	{
		*origin_a = new_a;
		*origin_b = new_b;
	}
}

/**
* TODO: has more than 25 lines. has to seperate.
*/
void	ft_set_best(t_list *list_a, t_list *list_b, int *prev_a, int *prev_b)
{
	int		prev_b;
	int		rotate_cnt_a;
	int		rotate_cnt_b;
	t_list	*ptr_a;
	t_list	*ptr_b;

	ptr_a = list_a;
	rotate_cnt_a = 0;
	while (ptr_a)
	{
		rotate_cnt_b = 0;
		ptr_b = list_b;
		prev_b = ft_lstlast(list_b)->content;
		while (ptr_a->content < ptr_b->content || ptr_b->content < prev_b)
		{
			prev_b = ptr_b->content;
			ptr_b = ptr_b->next;
			rotate_cnt_b++;
		}
		if (ft_lstsize(list_b) / 2 < rotate_cnt_b)
			rotate_cnt_b = -(ft_lstsize(list_b) - rotate_cnt_b);
		if (ft_lstsize(list_a) / 2 < rotate_cnt_a)
			rotate_cnt_a = -(ft_lstsize(list_a) - rotate_cnt_a);
		ft_set_better_rotate(prev_a, prev_b, rotate_cnt_a++, rotate_cnt_b);
		ptr_a = ptr_a->next;
	}
}

void	ft_best_rotate(t_list **list_a, t_list **list_b, int cnt_a, int cnt_b)
{
	while (0 < cnt_a && 0 < cnt_b)
	{
		ft_rr(list_a, list_b);
		cnt_a--;
		cnt_b--;
	}
	while (cnt_a < 0 && cnt_b < 0)
	{
		ft_rrr(list_a, list_b);
		cnt_a++;
		cnt_b++;
	}
	while (0 < cnt_a--)
		ft_ra(list_a, 1);
	while (++cnt_a < 0)
		ft_rra(list_a, 1);
	while (0 < cnt_b--)
		ft_rb(list_b, 1);
	while (++cnt_b < 0)
		ft_rrb(list_b, 1);
}

int	ft_get_rb_count_to_sort_b(t_list *list_b)
{
	int	prev_b;
	int	ptr_b;
	int	count;

	prev_b = ft_lstlast(list_b)->content;
	ptr_b = list_b;
	count = 0;
	while (prev_b < ptr_b->content)
	{
		ptr_b = ptr_b->next;
		count++;
	}
	return (count);
}

void	ft_sort(t_list **list_a, t_list **list_b)
{
	int	i;
	int	min_rotate_way_a;
	int	min_rotate_way_b;

	i = ft_lstsize(*list_a);
	while (i--)
	{
		min_rotate_way_ab = [0, 0];
		min_rotate_way_a = 0;
		min_rotate_way_b = 0;
		ft_set_best(*list_a, *list_b, &min_rotate_way_a, &min_rotate_way_b);
		ft_best_rotate(list_a, list_b, min_rotate_way_a, min_rotate_way_b);
		ft_pb(list_a, list_b);
	}
	i = ft_get_rb_count_to_sort_b(*list_b);
	while (i--)
		ft_rb(list_b, 1);
	i = ft_lstsize(*list_b);
	while (i--)
		ft_pa(list_a, list_b);
}
