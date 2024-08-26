/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:52:29 by younghoc          #+#    #+#             */
/*   Updated: 2024/08/26 13:52:30 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "object.h"
#include "panic.h"
#include "parse.h"

void	parse_light(t_list **lights, const char *line, size_t *i)
{
	t_light	*light;
	t_list	*node;

	light = malloc(sizeof(t_light));
	if (light == NULL)
		panic("failed to malloc");
	parse_vector3(&light->position, line, i);
	parse_decimal(&light->brightness, line, i);
	parse_vector3(&light->color, line, i);
	parse_newline(line, i);
	node = ft_lstnew(light);
	if (node == NULL)
		panic("failed to malloc");
	ft_lstadd_back(lights, node);
}
