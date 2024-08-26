/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_char.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 16:15:36 by younghoc          #+#    #+#             */
/*   Updated: 2024/08/26 13:54:15 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_CHAR_H
# define VECTOR_CHAR_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16
# endif

typedef struct s_vector_char
{
	char	*data;
	int		len;
	int		cap;
}	t_vector_char;

void		init_vector_char(t_vector_char *vector);
char		*push_back_char(t_vector_char *vector, char c);
char		*push_back_str(t_vector_char *vector, char *str);
void		destroy_vector_char(t_vector_char *vector);

#endif
