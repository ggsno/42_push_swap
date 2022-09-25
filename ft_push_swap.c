/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go <go@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 22:43:28 by go                #+#    #+#             */
/*   Updated: 2022/09/25 23:00:31 by go               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	is_sorted(t_list *head)
{
	int	min;

	min = -1;
	while (head)
	{
		if (head->content < min)
			return (0);
		min = head->content;
		head = head->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int 	i;
	t_list	*list_a;
	t_list	*temp;

	if (!ft_check_error(argc, &argv[2]))
		return (1);

	list_a = ft_create_list(argc, argv);
	return (0);
}

// i = 0;
// 	temp = list_a;
	// while (temp)
    // {
    //     ft_putstr(ft_itoa(temp->content));
	// 	temp = temp->next;
    // }    

	// ft_sb(&list_a, 1);
	// temp = list_a;
	// while (temp)
    // {
    //     ft_putstr(ft_itoa(temp->content));
	// 	temp = temp->next;
    // }
	// if (is_sorted(list_a))
	// 	ft_putstr("sorted");
	// ft_rrb(&list_a, 1);
	// temp = list_a;
	// while (temp)
    // {
    //     ft_putstr(ft_itoa(temp->content));
	// 	temp = temp->next;
    // }
	// if (is_sorted(list_a))
	// 	ft_putstr("sorted");
