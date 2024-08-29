/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_is_shadow.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:53:31 by younghoc          #+#    #+#             */
/*   Updated: 2024/08/29 19:02:13 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "environment.h"

int is_shadow(const t_environment *env, const t_vector3 ray, const double distance)
{
	const t_vector3	hit_point = add(get_camera(env)->position,
			scale(ray, distance));
	const t_vector3	to_light = normalize(subtract(get_light(env)->position, hit_point));
	const t_vector3	start_pos = subtract(hit_point, scale(ray, 0.0000001));
	const double	threshold = magnitude(subtract(hit_point, get_light(env)->position));
	double			distance2;

	get_closest_object(start_pos, to_light, env->objects, &distance2);
	return (distance2 < threshold);
}
