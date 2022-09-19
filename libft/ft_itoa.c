/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go <go@student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:49:34 by go                #+#    #+#             */
/*   Updated: 2022/03/11 15:33:31 by go               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_numlen(int n)
{
	int	result;

	if (n == 0)
		return (1);
	result = 0;
	if (n < 0)
		result++;
	while (n != 0)
	{
		n = n / 10;
		result++;
	}
	return (result);
}

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;

	len = ft_numlen(n);
	result = (char *)malloc(sizeof(char) * len + 1);
	if (!result)
		return (NULL);
	result[len--] = '\0';
	if (n == 0)
	{
		result[0] = '0';
		return (result);
	}
	while (n != 0)
	{
		result[len] = ft_abs(n % 10) + '0';
		n = n / 10;
		len--;
	}
	if (len == 0)
		result[0] = '-';
	return (result);
}
