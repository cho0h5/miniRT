/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:09:35 by younghoc          #+#    #+#             */
/*   Updated: 2023/10/26 11:26:19 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	char	*result;
	size_t	count;

	slen = ft_strlen(s);
	if (slen <= start)
		return (ft_strdup(""));
	count = min(slen - start, len);
	result = malloc(count + 1);
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, s + start, count + 1);
	return (result);
}
