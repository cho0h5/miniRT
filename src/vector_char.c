/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:52:47 by younghoc          #+#    #+#             */
/*   Updated: 2024/08/26 13:52:48 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "vector_char.h"

void	init_vector_char(t_vector_char *vector)
{
	vector->data = malloc(16);
	if (vector->data == NULL)
		exit(1);
	vector->len = 0;
	vector->cap = 16;
}

void	destroy_vector(t_vector_char *vector)
{
	vector->cap = 0;
	vector->len = 0;
	free(vector->data);
	vector->data = NULL;
}

static void	*ft_memcpy(void *new_addr, const void *addr, size_t copy_size)
{
	char		*new_addr_ptr;
	const char	*addr_ptr;
	size_t		i;

	new_addr_ptr = (char *)new_addr;
	addr_ptr = (const char *)addr;
	i = 0;
	while (i < copy_size)
	{
		new_addr_ptr[i] = addr_ptr[i];
		i++;
	}
	return (new_addr);
}

static void	*ft_realloc(void *addr, size_t old_size, size_t new_size)
{
	void	*new_addr;
	size_t	copy_size;

	if (addr == NULL)
		return (malloc(new_size));
	if (new_size == 0)
	{
		free(addr);
		return (NULL);
	}
	new_addr = malloc(new_size);
	if (new_addr == NULL)
	{
		free(addr);
		return (NULL);
	}
	copy_size = old_size;
	if (old_size > new_size)
		copy_size = new_size;
	ft_memcpy(new_addr, addr, copy_size);
	free(addr);
	return (new_addr);
}

char	*push_back_char(t_vector_char *vector, char c)
{
	if (vector->len == vector->cap - 1)
	{
		vector->data = (char *)ft_realloc(vector->data,
				vector->cap, vector->cap * 2);
		if (vector->data == NULL)
			exit(1);
		vector->cap *= 2;
	}
	vector->data[vector->len++] = c;
	return (vector->data);
}
