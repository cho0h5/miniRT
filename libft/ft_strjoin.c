/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:08:56 by younghoc          #+#    #+#             */
/*   Updated: 2023/10/26 11:58:45 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	const size_t	size = ft_strlen(s1) + ft_strlen(s2);
	char			*result;

	result = ft_calloc(size + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, s1, size + 1);
	ft_strlcat(result, s2, size + 1);
	return (result);
}
