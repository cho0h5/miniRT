/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:31:25 by younghoc          #+#    #+#             */
/*   Updated: 2023/11/25 13:25:52 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_getchar(t_buffer *head, int fd)
{
	t_buffer	*buffer;

	buffer = get_buffer(head, fd);
	if (buffer == NULL)
		return (-1);
	if (buffer->cursor >= buffer->len)
	{
		buffer->len = read(fd, buffer->buffer, BUFFER_SIZE);
		buffer->cursor = 0;
		if (buffer->len == 0)
		{
			free_buffer(head, fd);
			return (0);
		}
		if (buffer->len == -1)
		{
			free_buffer(head, fd);
			return (-1);
		}
	}
	return (buffer->buffer[buffer->cursor++]);
}

char	*get_next_line(int fd)
{
	static t_buffer	head = {-1, {0,}, 0, 0, NULL};
	t_vector		line;
	char			c;

	line = init_vector();
	if (line.data == NULL)
		return (free_buffer(&head, fd));
	while (1)
	{
		c = ft_getchar(&head, fd);
		if (c == 0)
			break ;
		if (c == -1)
			return (free_all(&head, fd, &line));
		if (push_back(&line, c) == NULL)
			return (free_buffer(&head, fd));
		if (c == '\n')
			break ;
	}
	if (push_back(&line, '\0') == NULL || line.data[0] == '\0'
		|| shrink_vector(&line) == NULL)
		return (free_all(&head, fd, &line));
	return (line.data);
}

t_vector	*shrink_vector(t_vector *vector)
{
	char	*shrinked;

	shrinked = malloc(vector->len);
	if (shrinked == NULL)
	{
		free(vector->data);
		vector->data = NULL;
		vector->cap = 0;
		vector->len = 0;
		return (NULL);
	}
	ft_memcpy(shrinked, vector->data, vector->len);
	free(vector->data);
	vector->data = shrinked;
	vector->cap = vector->len;
	return (vector);
}

t_vector	init_vector(void)
{
	t_vector	vector;

	vector.data = malloc(16);
	vector.len = 0;
	vector.cap = 16;
	return (vector);
}

void	*free_all(t_buffer *buffer, int fd, t_vector *vector)
{
	free_buffer(buffer, fd);
	free(vector->data);
	return (NULL);
}
