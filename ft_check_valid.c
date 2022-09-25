/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go <go@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 22:25:05 by go                #+#    #+#             */
/*   Updated: 2022/09/25 23:00:29 by go               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_atoi(const char *str)
{
	int			sign;
	long long	result;
	int			i;
	int			len;

	sign = 1;
	result = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] && '0' <= str[i] && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	if (result < -2147483648 || result > 2147483647 || ft_strlen(str) < i ||  )
	if ()
		return (0);
	return (1);
}


int ft_check_valid(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		
		argv[i]
	}
}
