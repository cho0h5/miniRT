/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_sphere_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:52:17 by younghoc          #+#    #+#             */
/*   Updated: 2024/08/29 13:42:59 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "environment.h"
#include "object.h"
#include "color.h"
#include "vector3.h"

static t_vector3	get_sphere_ambient(const t_sphere *sphere,
		const t_ambient *ambient)
{
	return (multiply(sphere->color,
			scale(ambient->color, ambient->ratio / 255)));
}

static t_vector3	get_sphere_diffuse(const t_sphere *sphere,
		const t_environment *env, const double distance)
{
	const t_vector3	hit_point = add(get_camera(env)->position,
			scale(get_camera(env)->orientation, distance));
	const t_vector3	normal = normalize(subtract(hit_point, sphere->position));
	const t_vector3	to_light = normalize(
			subtract(get_light(env)->position, hit_point));
	const double	diffuse_strength = fmax(0, dot(normal, to_light));
	const t_vector3	diffuse = scale(get_light(env)->color, diffuse_strength);

	return (diffuse);
}

unsigned int	get_sphere_color(const t_sphere *sphere,
						const t_environment *env, const double distance)
{
	const t_vector3	ambient = get_sphere_ambient(sphere, get_ambient(env));
	const t_vector3	diffuse = get_sphere_diffuse(sphere, env, distance);

	return (to_color(add(ambient, diffuse)));
}
