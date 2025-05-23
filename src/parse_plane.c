/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:52:34 by younghoc          #+#    #+#             */
/*   Updated: 2024/09/06 19:36:28 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "object.h"
#include "parse.h"
#include "panic.h"

void	parse_plane(t_list **objects, const char *line, size_t *i)
{
	t_object_category	*category;
	t_plane				*plane;
	t_list				*node;

	category = malloc(sizeof(t_object_category) + sizeof(t_plane));
	if (category == NULL)
		panic("failed to malloc");
	*category = OBJ_PLANE;
	plane = (t_plane *)((void *)category + sizeof(t_object_category));
	parse_vector3(&plane->position, line, i);
	parse_vector3(&plane->normal, line, i);
	normalize_orientation(&plane->normal);
	parse_vector3(&plane->color, line, i);
	parse_newline(line, i);
	node = ft_lstnew(category);
	if (node == NULL)
		panic("failed to malloc");
	ft_lstadd_back(objects, node);
}
