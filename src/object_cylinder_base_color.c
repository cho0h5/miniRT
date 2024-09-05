/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_cylinder_base_color.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:21:29 by younghoc          #+#    #+#             */
/*   Updated: 2024/09/05 20:21:30 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "environment.h"
#include "object.h"
#include "color.h"
#include "vector3.h"

static t_vector3	get_cylinder_base_ambient(const t_cylinder_base *cylinder_base,
		const t_ambient *ambient)
{
	return (multiply(cylinder_base->color,
			scale(ambient->color, ambient->ratio / 255)));
}

static t_vector3	get_normal_vector(const t_vector3 cylinder_base_normal,
		const t_vector3 ray)
{
	if (dot(cylinder_base_normal, ray) < 0)
		return (cylinder_base_normal);
	else
		return (scale(cylinder_base_normal, -1));
}

static t_vector3	get_cylinder_base_diffuse(const t_cylinder_base *cylinder_base,
						const t_environment *env, const t_vector3 ray,
						const double distance)
{
	const t_vector3	normal = get_normal_vector(cylinder_base->normal, ray);
	const t_vector3	hit_point = add(get_camera(env)->position,
			scale(ray, distance));
	const t_vector3	to_light = normalize(
			subtract(get_light(env)->position, hit_point));
	const double	diffuse_strength = fmax(0, dot(normal, to_light))
		* get_light(env)->brightness;

	return (multiply(cylinder_base->color,
			scale(get_light(env)->color, diffuse_strength / 255)));
}

unsigned int	get_cylinder_base_color(const t_cylinder_base *cylinder_base,
						const t_environment *env, const t_vector3 ray,
						const double distance)
{
	const t_vector3	ambient = get_cylinder_base_ambient(cylinder_base, get_ambient(env));
	const t_vector3	diffuse = get_cylinder_base_diffuse(cylinder_base, env, ray, distance);

	if (is_shadow(env, ray, distance))
		return (to_color(ambient));
	else
		return (to_color(add(ambient, diffuse)));
}
