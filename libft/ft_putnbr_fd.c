/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go <go@student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:19:41 by go                #+#    #+#             */
/*   Updated: 2022/03/11 17:38:51 by go               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	number[10];
	int		i;

	i = 0;
	if (n < 0)
		write(fd, "-", 1);
	while (n || i == 0)
	{
		number[i++] = ft_abs(n % 10) + '0';
		n /= 10;
	}
	while (i--)
		write(fd, &number[i], 1);
}
