/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_plane_distance.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:52:11 by younghoc          #+#    #+#             */
/*   Updated: 2024/08/26 13:52:12 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "vector3.h"

double	plane_distance(const t_vector3 pos, const t_vector3 ray, const t_plane *plane)
{
	const t_vector3	pc_vec = subtract(plane->position, pos);
	const double	numerator = dot(pc_vec, plane->normal);
	const double	denominator = dot(ray, plane->normal);
	const double	distance = numerator / denominator;

	if (distance <= 0)
		return (DOUBLE_MAX);
	return (distance);
}
