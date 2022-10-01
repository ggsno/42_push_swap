/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_rotate_count.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go <go@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 22:02:51 by go                #+#    #+#             */
/*   Updated: 2022/10/01 22:04:18 by go               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_get_rotate_count(t_list *la, int rotate_cnt_a)
{
	if ((ft_lstsize(la) + rotate_cnt_a) / 2 < rotate_cnt_a)
		return (-(ft_lstsize(la)));
	return (rotate_cnt_a);
}
