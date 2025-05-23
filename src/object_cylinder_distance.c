/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_cylinder_distance.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:51:57 by younghoc          #+#    #+#             */
/*   Updated: 2024/09/05 19:37:41 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "object.h"
#include "vector3.h"
#include "equation.h"

double	calculate_hypotenuse_length(const t_vector3 ray,
				const t_cylinder *cylinder, const double distance_skew)
{
	const double	hypotenuse_on_plane = sqrt((cylinder->diameter / 2)
			* (cylinder->diameter / 2) - distance_skew * distance_skew);
	const double	theta = fabs(acos(angle(cylinder->axis, ray)));

	return (hypotenuse_on_plane / sin(theta));
}

double	calculate_height_length(const t_vector3 ray,
				const t_cylinder *cylinder, const double distance_skew)
{
	const double	hypotenuse_on_plane = sqrt((cylinder->diameter / 2)
			* (cylinder->diameter / 2) - distance_skew * distance_skew);
	const double	theta = fabs(acos(angle(cylinder->axis, ray)));

	return (hypotenuse_on_plane / tan(theta));
}

double	cylinder_distance(const t_vector3 pos, const t_vector3 ray,
				const t_cylinder *cylinder)
{
	const t_vector3	normal_vec = normalize(cross(ray, cylinder->axis));
	const double	distance_skew = dot(subtract(pos, cylinder->position),
			normal_vec);
	const double	t = closest_point_on_skew_lines(pos, ray,
			cylinder->position, cylinder->axis);
	const double	s = closest_point_on_skew_lines(cylinder->position,
			cylinder->axis, pos, ray);
	double			hypotenuse;

	if (fabs(distance_skew) > cylinder->diameter / 2)
		return (DOUBLE_MAX);
	hypotenuse = calculate_hypotenuse_length(ray, cylinder, distance_skew);
	if (t - hypotenuse >= 0
		&& fabs(s - calculate_height_length(ray, cylinder, distance_skew))
		<= cylinder->height / 2)
		return (t - hypotenuse);
	if (t + hypotenuse >= 0
		&& fabs(s + calculate_height_length(ray, cylinder, distance_skew))
		<= cylinder->height / 2)
		return (t + hypotenuse);
	return (DOUBLE_MAX);
}
