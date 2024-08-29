/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:51:53 by younghoc          #+#    #+#             */
/*   Updated: 2024/08/29 15:54:38 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "object.h"
#include "panic.h"
#include "color.h"

unsigned int	get_object_color(const t_object_category *object_category,
						const t_environment *env, const t_vector3 ray,
						const double distance)
{
	const void	*object = (void *)object_category + sizeof(t_object_category);

	if (*object_category == OBJ_PLANE)
		return (get_plane_color(object, env, ray, distance));
	if (*object_category == OBJ_SPHERE)
		return (get_sphere_color(object, env, ray, distance));
	if (*object_category == OBJ_CYLINDER)
		return (get_cylinder_color(object, env, ray, distance));
	panic("failed to get object color: unexpected object");
	return (-1);
}
