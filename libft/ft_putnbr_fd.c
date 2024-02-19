/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:08:13 by younghoc          #+#    #+#             */
/*   Updated: 2023/10/15 15:08:20 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	recursion_print(long long num, int fd)
{
	char	c;

	if (num > 0)
	{
		c = num % 10 + '0';
		num /= 10;
		recursion_print(num, fd);
		ft_putchar_fd(c, fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long long	num;

	num = n;
	if (num == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	else if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num = -num;
	}
	recursion_print(num, fd);
}
