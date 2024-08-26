/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_char_push_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:52:46 by younghoc          #+#    #+#             */
/*   Updated: 2024/08/26 13:52:47 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_char.h"
#include "libft.h"

char	*push_str_back(t_vector_char *vector, char *str)
{
	const size_t	strlen = ft_strlen(str);
	size_t			i;

	i = 0;
	while (i < strlen)
	{
		push_back_char(vector, str[i]);
		i++;
	}
	return (vector->data);
}
