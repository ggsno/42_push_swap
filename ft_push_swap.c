/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go <go@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 22:43:28 by go                #+#    #+#             */
/*   Updated: 2022/10/01 19:04:07 by go               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	is_sorted(t_list *head)
{
	int	min;

	min = -1;
	while (head)
	{
		if (head->c < min)
			return (0);
		min = head->c;
		head = head->n;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;

	if (argc < 2)
		return (1);
	list_a = NULL;
	ft_set_list(argc, argv, &list_a);
	list_b = NULL;
	ft_sort(&list_a, &list_b);
	return (0);
}

// i = 0;
// 	temp = list_a;
	// while (temp)
    // {
    //     ft_putstr(ft_itoa(temp->c));
	// 	temp = temp->n;
    // }    

	// ft_sb(&list_a, 1);
	// temp = list_a;
	// while (temp)
    // {
    //     ft_putstr(ft_itoa(temp->c));
	// 	temp = temp->n;
    // }
	// if (is_sorted(list_a))
	// 	ft_putstr("sorted");
	// ft_rrb(&list_a, 1);
	// temp = list_a;
	// while (temp)
    // {
    //     ft_putstr(ft_itoa(temp->c));
	// 	temp = temp->n;
    // }
	// if (is_sorted(list_a))
	// 	ft_putstr("sorted");
