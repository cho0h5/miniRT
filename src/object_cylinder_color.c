/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_cylinder_color.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:51:54 by younghoc          #+#    #+#             */
/*   Updated: 2024/08/29 20:30:43 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "environment.h"
#include "object.h"
#include "color.h"
#include "equation.h"

static t_vector3	get_cylinder_ambient(const t_cylinder *cylinder,
		const t_ambient *ambient)
{
	return (multiply(cylinder->color,
			scale(ambient->color, ambient->ratio / 255)));
}

static t_vector3	get_cylinder_diffuse(const t_cylinder *cylinder,
						const t_environment *env, const t_vector3 ray,
						const double distance)
{
	const double	s = closest_point_on_skew_lines(cylinder->position,
			cylinder->axis, get_camera(env)->position, ray);
	const t_vector3	center = add(cylinder->position, scale(cylinder->axis, s));
	const t_vector3	hit_point = add(get_camera(env)->position,
			scale(ray, distance));
	const t_vector3	normal = normalize(subtract(hit_point, center));
	const t_vector3	to_light = normalize(
			subtract(get_light(env)->position, hit_point));
	const double	diffuse_strength = fmax(0, dot(normal, to_light))
		* get_light(env)->brightness;
	const t_vector3	diffuse = multiply(cylinder->color,
			scale(get_light(env)->color, diffuse_strength / 255));

	return (diffuse);
}

unsigned int	get_cylinder_color(const t_cylinder *cylinder,
						const t_environment *env, const t_vector3 ray,
						const double distance)
{
	const t_vector3	ambient = get_cylinder_ambient(cylinder, get_ambient(env));
	const t_vector3	diffuse = get_cylinder_diffuse(cylinder, env, ray,
			distance);

	if (is_shadow(env, ray, distance))
		return (to_color(ambient));
	else
		return (to_color(add(ambient, diffuse)));
}
