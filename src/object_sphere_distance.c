/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_sphere_distance.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:52:18 by younghoc          #+#    #+#             */
/*   Updated: 2024/08/26 13:52:19 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "object.h"
#include "vector3.h"

double	sphere_distance(const t_vector3 pos, const t_vector3 ray, const t_sphere *sphere)
{
	const t_vector3	sp_vec = subtract(pos, sphere->position);
	const double	radius = sphere->diameter / 2;
	const double	b = 2 * dot(sp_vec, ray);
	const double	c = dot(sp_vec, sp_vec) - radius * radius;
	const double	discriminant = b * b - 4 * c;

	if (discriminant < 0)
		return (DOUBLE_MAX);
	if (-b - sqrt(discriminant) >= 0)
		return ((-b - sqrt(discriminant)) / 2);
	if (-b + sqrt(discriminant) >= 0)
		return ((-b + sqrt(discriminant)) / 2);
	return (DOUBLE_MAX);
}
