/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:09:00 by younghoc          #+#    #+#             */
/*   Updated: 2023/10/15 16:44:37 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	int		dstlen;

	i = 0;
	while (i < dstsize && dst[i] != '\0')
		i++;
	dstlen = i;
	if (i == dstsize)
		return (dstlen + ft_strlen(src));
	i = 0;
	while (src[i] != '\0' && dstlen + i + 1 < dstsize)
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + ft_strlen(src));
}
