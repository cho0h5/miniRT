/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:31:40 by younghoc          #+#    #+#             */
/*   Updated: 2023/11/25 13:22:42 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *new_addr, const void *addr, size_t copy_size)
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

void	*ft_realloc(void *addr, size_t old_size, size_t new_size)
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

char	*push_back(t_vector *vector, char c)
{
	if (vector->len == vector->cap - 1)
	{
		vector->data = (char *)ft_realloc(vector->data,
				vector->cap, vector->cap * 2);
		if (vector->data == NULL)
		{
			vector->cap = 0;
			vector->len = 0;
			return (NULL);
		}
		vector->cap *= 2;
	}
	vector->data[vector->len++] = c;
	return (vector->data);
}

t_buffer	*get_buffer(t_buffer *buffer, int fd)
{
	if (fd < 0)
		return (NULL);
	while (buffer->next != NULL)
	{
		buffer = buffer->next;
		if (buffer->fd == fd)
			return (buffer);
	}
	buffer->next = malloc(sizeof(t_buffer));
	buffer = buffer->next;
	if (buffer == NULL)
		return (NULL);
	buffer->fd = fd;
	buffer->len = 0;
	buffer->cursor = 0;
	buffer->next = NULL;
	return (buffer);
}

void	*free_buffer(t_buffer *buffer, int fd)
{
	t_buffer	*target;

	if (fd < 0)
		return (NULL);
	while (buffer->next != NULL)
	{
		if (buffer->next->fd == fd)
		{
			target = buffer->next;
			buffer->next = target->next;
			free(target);
			return (NULL);
		}
		buffer = buffer->next;
	}
	return (NULL);
}
