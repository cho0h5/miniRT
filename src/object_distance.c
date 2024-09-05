/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_distance.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:52:05 by younghoc          #+#    #+#             */
/*   Updated: 2024/09/05 19:45:11 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "panic.h"
#include "vector3.h"

double	object_distance(const t_vector3 pos, const t_vector3 ray,
				const t_object_category *object_category)
{
	const void	*object = (void *)object_category + sizeof(t_object_category);

	if (*object_category == OBJ_PLANE)
		return (plane_distance(pos, ray, object));
	if (*object_category == OBJ_SPHERE)
		return (sphere_distance(pos, ray, object));
	if (*object_category == OBJ_CYLINDER)
		return (cylinder_distance(pos, ray, object));
	if (*object_category == OBJ_CYLINDER_BASE)
		return (cylinder_base_distance(pos, ray, object));
	panic("failed to get object distance: unexpected object");
	return (DOUBLE_MAX);
}
