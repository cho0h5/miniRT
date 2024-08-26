/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_cylinder_distance.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:51:57 by younghoc          #+#    #+#             */
/*   Updated: 2024/08/26 19:47:31 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "object.h"
#include "vector3.h"
#include "equation.h"

double	cylinder_distance(const t_vector3 pos, const t_vector3 ray,
				const t_cylinder *cylinder)
{
	const t_vector3	normal_vec = normalize(cross(ray, cylinder->axis));
	const double	distance = dot(subtract(pos, cylinder->position),
			normal_vec);
	const double	t = closest_point_on_skew_lines(pos, ray,
			cylinder->position, cylinder->axis);
	const double	s = closest_point_on_skew_lines(cylinder->position,
			cylinder->axis, pos, ray);

	if (fabs(distance) <= cylinder->diameter / 2
		&& fabs(s) <= cylinder->height / 2)
		return (distance);
	return (DOUBLE_MAX);
}
