/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:09:18 by younghoc          #+#    #+#             */
/*   Updated: 2023/10/27 19:55:44 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*str1 = (unsigned char*)s1;
	const unsigned char	*str2 = (unsigned char*)s2;
	size_t				i;

	if (n == 0)
		return (0);
	i = 0;
	while (str1[i] != '\0' && str2[i] != '\0'
		&& str1[i] == str2[i] && i < n - 1)
		i++;
	return (str1[i] - str2[i]);
}
