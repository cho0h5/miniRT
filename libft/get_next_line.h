/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:31:30 by younghoc          #+#    #+#             */
/*   Updated: 2023/11/25 13:31:09 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16
# endif

typedef struct s_buffer
{
	int				fd;
	char			buffer[BUFFER_SIZE];
	int				len;
	int				cursor;
	struct s_buffer	*next;
}	t_buffer;

typedef struct s_vector
{
	char	*data;
	int		len;
	int		cap;
}	t_vector;

char		*get_next_line(int fd);
int			ft_getchar(t_buffer *head, int fd);

t_vector	init_vector(void);
t_vector	*shrink_vector(t_vector *vector);
char		*push_back(t_vector *vector, char c);

void		*ft_memcpy(void *new_addr, const void *addr, size_t copy_size);
void		*ft_realloc(void *addr, size_t old_size, size_t new_size);

t_buffer	*get_buffer(t_buffer *buffer, int fd);
void		*free_buffer(t_buffer *buffer, int fd);

void		*free_all(t_buffer *buffer, int fd, t_vector *vector);

#endif
