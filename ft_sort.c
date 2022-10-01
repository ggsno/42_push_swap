/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go <go@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 06:15:52 by go                #+#    #+#             */
/*   Updated: 2022/10/01 22:03:30 by go               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	ft_set_better_rotate(int *old_a, int *old_b, int new_a, int new_b)
{
	int	origin_cnt;
	int	new_cnt;

	origin_cnt = 0;
	new_cnt = 0;
	if ((0 < *old_a && 0 < *old_b) || (*old_a < 0 && *old_b < 0))
		origin_cnt = ft_get_bigger(ft_abs(*old_a), ft_abs(*old_b));
	else
		origin_cnt = ft_abs(*old_a) + ft_abs(*old_b);
	if ((0 < new_a && 0 < new_b) || (new_a < 0 && new_b < 0))
		new_cnt = ft_get_bigger(ft_abs(new_a), ft_abs(new_b));
	else
		new_cnt = ft_abs(new_a) + ft_abs(new_b);
	if (new_cnt < origin_cnt)
	{
		*old_a = new_a;
		*old_b = new_b;
	}
}



static void	ft_set_best(t_list *la, t_list *lb, int *min_a, int *min_b)
{
	int		pb;
	int		rotate_cnt_a;
	int		rotate_cnt_b;
	t_list	*b;

	rotate_cnt_a = 0;
	while (la)
	{
		rotate_cnt_b = 0;
		b = lb;
		pb = ft_lstlast(lb)->c;
		while (b && !(b->c < la->c && la->c < pb) && \
			!(pb < b->c && (b->c < la->c || la->c < pb)))
		{
			pb = b->c;
			b = b->n;
			rotate_cnt_b++;
		}
		if (ft_lstsize(lb) / 2 < rotate_cnt_b)
			rotate_cnt_b = -(ft_lstsize(lb) - rotate_cnt_b);
		pb = ft_get_rotate_count(la, rotate_cnt_a);
		ft_set_better_rotate(min_a, min_b, pb, rotate_cnt_b);
		rotate_cnt_a++;
		la = la->n;
	}
}

static void	ft_best_rotate(t_list **lst_a, t_list **lst_b, int cnt_a, int cnt_b)
{
	while (0 < cnt_a && 0 < cnt_b)
	{
		ft_rr(lst_a, lst_b);
		cnt_a--;
		cnt_b--;
	}
	while (cnt_a < 0 && cnt_b < 0)
	{
		ft_rrr(lst_a, lst_b);
		cnt_a++;
		cnt_b++;
	}
	while (0 < cnt_a--)
		ft_ra(lst_a, 1);
	while (++cnt_a < 0)
		ft_rra(lst_a, 1);
	while (0 < cnt_b--)
		ft_rb(lst_b, 1);
	while (++cnt_b < 0)
		ft_rrb(lst_b, 1);
}

static void	ft_rb_sort_b(t_list **list_b)
{
	int		prev_b;
	int		count;
	t_list	*ptr_b;

	prev_b = ft_lstlast(*list_b)->c;
	count = 0;
	ptr_b = *list_b;
	while (ptr_b->c < prev_b)
	{
		prev_b = ptr_b->c;
		ptr_b = ptr_b->n;
		count++;
	}
	if (ft_lstsize(*list_b) / 2 < count)
	{
		count = ft_lstsize(*list_b) - count;
		while (count--)
			ft_rrb(list_b, 1);
	}
	else
		while (count--)
			ft_rb(list_b, 1);
}

void	ft_sort(t_list **list_a, t_list **list_b)
{
	int	i;
	int	min_rotate_way_a;
	int	min_rotate_way_b;

	i = ft_lstsize(*list_a) - 1;
	ft_pb(list_a, list_b);
	while (i--)
	{
		min_rotate_way_a = 2147483647;
		min_rotate_way_b = 2147483647;
		ft_set_best(*list_a, *list_b, &min_rotate_way_a, &min_rotate_way_b);
		ft_best_rotate(list_a, list_b, min_rotate_way_a, min_rotate_way_b);
		ft_pb(list_a, list_b);
	}
	ft_rb_sort_b(list_b);
	i = ft_lstsize(*list_b);
	while (i--)
		ft_pa(list_a, list_b);
}
