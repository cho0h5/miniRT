/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_plane_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:52:09 by younghoc          #+#    #+#             */
/*   Updated: 2024/09/05 18:49:45 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "environment.h"
#include "object.h"
#include "color.h"
#include "vector3.h"

static t_vector3	get_plane_ambient(const t_plane *plane,
		const t_ambient *ambient)
{
	return (multiply(plane->color,
			scale(ambient->color, ambient->ratio / 255)));
}

static t_vector3	get_normal_vector(const t_vector3 plane_normal,
		const t_vector3 ray)
{
	if (dot(plane_normal, ray) < 0)
		return (plane_normal);
	else
		return (scale(plane_normal, -1));
}

static t_vector3	get_plane_diffuse(const t_plane *plane,
						const t_environment *env, const t_vector3 ray,
						const double distance)
{
	const t_vector3	normal = get_normal_vector(plane->normal, ray);
	const t_vector3	hit_point = add(get_camera(env)->position,
			scale(ray, distance));
	const t_vector3	to_light = normalize(
			subtract(get_light(env)->position, hit_point));
	const double	diffuse_strength = fmax(0, dot(normal, to_light))
		* get_light(env)->brightness;

	return (multiply(plane->color,
			scale(get_light(env)->color, diffuse_strength / 255)));
}

unsigned int	get_plane_color(const t_plane *plane,
						const t_environment *env, const t_vector3 ray,
						const double distance)
{
	const t_vector3	ambient = get_plane_ambient(plane, get_ambient(env));
	const t_vector3	diffuse = get_plane_diffuse(plane, env, ray, distance);

	if (is_shadow(env, ray, distance))
		return (to_color(ambient));
	else
		return (to_color(add(ambient, diffuse)));
}
