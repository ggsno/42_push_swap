/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go <go@student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:13:01 by go                #+#    #+#             */
/*   Updated: 2022/03/11 17:14:23 by go               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{	
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
		i++;
	write(1, s, sizeof(*s) * i);
	return (i);
}