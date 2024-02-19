/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:09:27 by younghoc          #+#    #+#             */
/*   Updated: 2023/10/26 11:38:53 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*result;

	i = 0;
	result = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			result = (char *)&s[i];
		i++;
	}
	if (s[i] == (char)c)
		result = (char *)&s[i];
	return (result);
}
