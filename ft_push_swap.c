/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go <go@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 22:43:28 by go                #+#    #+#             */
/*   Updated: 2022/09/25 21:07:55 by go               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	int 	i;
	t_list	*list_a;
	t_list	*temp;

	if (!ft_check_error(argc, &argv[2]))
		return (1);

	list_a = ft_create_list(argc, argv);
	i = 0;
	temp = list_a;

	while (temp)
    {
        ft_printf("%s ", temp->content);
		temp = temp->next;
    }    

	ft_rb(&list_a, 1);
	temp = list_a;
	while (temp)
    {
        ft_printf("%s ", temp->content);
		temp = temp->next;
    }
	ft_rrb(&list_a, 1);
	temp = list_a;
	while (temp)
    {
        ft_printf("%s ", temp->content);
		temp = temp->next;
    }
		return (0);
}
