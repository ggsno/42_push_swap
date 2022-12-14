/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go <go@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:30:32 by go                #+#    #+#             */
/*   Updated: 2022/09/29 10:06:48 by go               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

int	ft_sa(t_list **list_a, int is_print)
{
	int	temp;

	if (!(*list_a) || !(*list_a)->n)
		return (0);
	temp = (*list_a)->c;
	(*list_a)->c = (*list_a)->n->c;
	(*list_a)->n->c = temp;
	if (is_print == 1)
		ft_putstr("sa\n");
	return (1);
}

int	ft_sb(t_list **list_b, int is_print)
{
	int	temp;

	if (!(*list_b) || !(*list_b)->n)
		return (0);
	temp = (*list_b)->c;
	(*list_b)->c = (*list_b)->n->c;
	(*list_b)->n->c = temp;
	if (is_print == 1)
		ft_putstr("sb\n");
	return (1);
}

int	ft_ss(t_list **list_a, t_list **list_b)
{
	if (!ft_sa(list_a, 0) || !ft_sb(list_b, 0))
		return (0);
	ft_putstr("ss\n");
	return (1);
}
