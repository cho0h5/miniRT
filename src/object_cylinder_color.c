/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_cylinder_color.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:51:54 by younghoc          #+#    #+#             */
/*   Updated: 2024/09/05 19:37:51 by younghoc         ###   ########.fr       */
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

static double	get_h(const t_cylinder *cylinder, const t_environment *env,
		const t_vector3 ray, const double distance_skew)
{
	const double	t = closest_point_on_skew_lines(get_camera(env)->position,
			ray, cylinder->position, cylinder->axis);
	const double	s = closest_point_on_skew_lines(cylinder->position,
			cylinder->axis, get_camera(env)->position, ray);
	const double	hypotenuse = calculate_hypotenuse_length(ray, cylinder,
			distance_skew);
	const double	height = calculate_height_length(ray, cylinder,
			distance_skew);

	if (t - hypotenuse >= 0 && fabs(s - height) <= cylinder->height / 2)
		return (s - height);
	else
		return (s + height);
}

static t_vector3	get_normal_vector(const t_cylinder *cylinder,
						const t_environment *env, const t_vector3 ray,
						const t_vector3 hit_point)
{
	const t_vector3	normal_vec = normalize(cross(ray, cylinder->axis));
	const double	distance_skew = dot(subtract(get_camera(env)->position,
				cylinder->position), normal_vec);
	const t_vector3	center = add(cylinder->position, scale(cylinder->axis,
				get_h(cylinder, env, ray, distance_skew)));
	const t_vector3	cylinder_normal = normalize(subtract(hit_point, center));

	if (dot(cylinder_normal, ray) < 0)
		return (cylinder_normal);
	else
		return (scale(cylinder_normal, -1));
}

static t_vector3	get_cylinder_diffuse(const t_cylinder *cylinder,
						const t_environment *env, const t_vector3 ray,
						const double distance)
{
	const t_vector3	hit_point = add(get_camera(env)->position,
			scale(ray, distance));
	const t_vector3	normal = get_normal_vector(cylinder, env, ray, hit_point);
	const t_vector3	to_light = normalize(
			subtract(get_light(env)->position, hit_point));
	const double	diffuse_strength = fmax(0, dot(normal, to_light))
		* get_light(env)->brightness;

	return (multiply(cylinder->color,
			scale(get_light(env)->color, diffuse_strength / 255)));
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
