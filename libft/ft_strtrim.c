/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:09:31 by younghoc          #+#    #+#             */
/*   Updated: 2023/10/26 11:59:18 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	const size_t	s1len = ft_strlen(s1);
	size_t			start;
	size_t			end;
	char			*result;

	start = 0;
	while (start < s1len && ft_strchr(set, s1[start]))
		start++;
	end = s1len;
	while (end > 0 && ft_strchr(set, s1[end]))
		end--;
	result = ft_substr(s1, start, end - start + 1);
	return (result);
}
