/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_cylinder_base_distance.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:21:51 by younghoc          #+#    #+#             */
/*   Updated: 2024/09/06 19:45:31 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "object.h"
#include "vector3.h"
#include "equation.h"

double	cylinder_base_distance(const t_vector3 pos, const t_vector3 ray,
				const t_cylinder_base *cylinder_base)
{
	const t_vector3	pc_vec = subtract(cylinder_base->position, pos);
	const double	numerator = dot(pc_vec, cylinder_base->normal);
	const double	denominator = dot(ray, cylinder_base->normal);
	const double	distance = numerator / denominator;
	const t_vector3	hit_point = add(pos, scale(ray, distance));

	if (distance > 0
		&& magnitude(subtract(hit_point, cylinder_base->position))
		<= cylinder_base->diameter / 2)
		return (distance);
	return (DOUBLE_MAX);
}
