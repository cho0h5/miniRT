/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_identifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:52:28 by younghoc          #+#    #+#             */
/*   Updated: 2024/08/26 13:52:29 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"

t_identifier	parse_identifier(const char *line, size_t *i)
{
	char			*word;
	t_identifier	id;

	skip_space(line, i);
	word = parse_word(line, i);
	if (ft_strncmp(word, "A", 2) == 0)
		id = ID_AMBIENT;
	else if (ft_strncmp(word, "C", 2) == 0)
		id = ID_CAMERA;
	else if (ft_strncmp(word, "L", 2) == 0)
		id = ID_LIGHT;
	else if (ft_strncmp(word, "pl", 3) == 0)
		id = ID_PLANE;
	else if (ft_strncmp(word, "sp", 3) == 0)
		id = ID_SPHERE;
	else if (ft_strncmp(word, "cy", 3) == 0)
		id = ID_CYLINDER;
	else if (ft_strncmp(word, "\n", 2) == 0)
		id = ID_EMPTY_LINE;
	else
		id = ID_UNKNOWN;
	free(word);
	skip_space(line, i);
	return (id);
}
