/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:05:55 by younghoc          #+#    #+#             */
/*   Updated: 2023/10/27 19:50:21 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*alloc_itoa(int sign, char *temp, size_t i)
{
	char	*result;
	size_t	j;

	result = ft_calloc(i + sign + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	if (sign)
		result[0] = '-';
	j = 0;
	while (j < i)
	{
		result[j + sign] = temp[i - j - 1];
		j++;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	long long	num;
	char		temp[10];
	size_t		i;
	int			sign;

	i = 0;
	num = n;
	sign = 0;
	if (num < 0)
	{
		sign = 1;
		num = -num;
	}
	if (num == 0)
		temp[i++] = '0';
	while (num > 0)
	{
		temp[i++] = num % 10 + '0';
		num /= 10;
	}
	return (alloc_itoa(sign, temp, i));
}
