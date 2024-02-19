/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:09:22 by younghoc          #+#    #+#             */
/*   Updated: 2023/10/26 10:41:29 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needlelen;
	size_t	haystacklen;

	if (len == 0 && haystack == NULL)
		return (NULL);
	needlelen = ft_strlen(needle);
	haystacklen = ft_strlen(haystack);
	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	if (len < needlelen)
		return (NULL);
	while (i < len - needlelen + 1)
	{
		if (i >= haystacklen)
			return (NULL);
		if (ft_strncmp(&haystack[i], needle, needlelen) == 0)
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
