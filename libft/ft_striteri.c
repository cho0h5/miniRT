/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:32:44 by younghoc          #+#    #+#             */
/*   Updated: 2023/10/27 19:59:05 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	const size_t	slen = ft_strlen(s);
	unsigned int	i;

	i = 0;
	while (i < slen)
	{
		f(i, &s[i]);
		i++;
	}
}
