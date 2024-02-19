/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:08:45 by younghoc          #+#    #+#             */
/*   Updated: 2023/10/26 11:59:52 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	const size_t	slen = ft_strlen(s1);
	char			*result;
	size_t			i;

	result = malloc(slen + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < slen + 1)
	{
		result[i] = s1[i];
		i++;
	}
	return (result);
}
