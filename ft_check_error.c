/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go <go@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 23:38:13 by go                #+#    #+#             */
/*   Updated: 2022/10/02 16:59:12 by go               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	check_number(const char *str, size_t i, long long result, int s)
{
	if (!str[i] || ('0' > str[i] || str[i] > '9'))
		return (0);
	while (str[i] && '0' <= str[i] && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		if ((s > 0 && result > 2147483647) || \
		(s < 0 && result * s < -2147483648))
			return (0);
		i++;
	}
	if (ft_strlen(str) > i)
		return (0);
	return (1);
}

int	ft_is_valid_letter(const char *str)
{
	int			sign;
	long long	result;
	size_t		i;

	sign = 1;
	result = 0;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	return (check_number(str, i, result, sign));
}

void	ft_print_error_exit(int err_no)
{
	ft_putstr("Error\n");
	exit(err_no);
}
