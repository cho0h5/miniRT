/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:24:54 by younghoc          #+#    #+#             */
/*   Updated: 2023/10/14 18:38:54 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	const size_t	slen = ft_strlen(s);
	size_t			i;
	char			*result;

	result = ft_calloc(slen + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < slen)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	return (result);
}
