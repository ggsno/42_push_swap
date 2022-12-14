/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go <go@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 06:23:25 by go                #+#    #+#             */
/*   Updated: 2022/09/29 14:19:34 by go               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

int	ft_lstsize(t_list *list)
{
	int	size;

	size = 0;
	while (list)
	{
		list = list->n;
		size++;
	}
	return (size);
}
