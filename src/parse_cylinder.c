/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:52:25 by younghoc          #+#    #+#             */
/*   Updated: 2024/09/05 20:05:44 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "object.h"
#include "parse.h"
#include "panic.h"

static void	add_base(t_list **objects, const t_cylinder *cylinder,
		const double height)
{
	t_object_category	*category;
	t_cylinder_base		*cylinder_base;
	t_list				*node;

	category = malloc(sizeof(t_object_category) + sizeof(t_cylinder_base));
	if (category == NULL)
		panic("failed to malloc");
	*category = OBJ_CYLINDER_BASE;
	cylinder_base = (t_cylinder_base *)((void *)category
			+ sizeof(t_object_category));
	cylinder_base->position = add(cylinder->position,
			scale(cylinder->axis, height));
	cylinder_base->normal = cylinder->axis;
	cylinder_base->diameter = cylinder->diameter;
	cylinder_base->color = cylinder->color;
	node = ft_lstnew(category);
	if (node == NULL)
		panic("failed to malloc");
	ft_lstadd_back(objects, node);
}

void	parse_cylinder(t_list **objects, const char *line, size_t *i)
{
	t_object_category	*category;
	t_cylinder			*cylinder;
	t_list				*node;

	category = malloc(sizeof(t_object_category) + sizeof(t_cylinder));
	if (category == NULL)
		panic("failed to malloc");
	*category = OBJ_CYLINDER;
	cylinder = (t_cylinder *)((void *)category + sizeof(t_object_category));
	parse_vector3(&cylinder->position, line, i);
	parse_vector3(&cylinder->axis, line, i);
	parse_decimal(&cylinder->diameter, line, i);
	parse_decimal(&cylinder->height, line, i);
	parse_vector3(&cylinder->color, line, i);
	parse_newline(line, i);
	node = ft_lstnew(category);
	if (node == NULL)
		panic("failed to malloc");
	ft_lstadd_back(objects, node);
	add_base(objects, cylinder, cylinder->height / 2);
	add_base(objects, cylinder, -cylinder->height / 2);
}
