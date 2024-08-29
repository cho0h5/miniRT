/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_is_shadow.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:53:31 by younghoc          #+#    #+#             */
/*   Updated: 2024/08/29 18:53:33 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "environment.h"

int is_shadow(const t_environment *env, const t_vector3 ray, const double distance)
{
	const t_vector3	hit_point = add(get_camera(env)->position,
			scale(ray, distance));
	const double	threshold = magnitude(subtract(hit_point, get_light(env)->position));
	double			distance2;

	get_closest_object(hit_point, normalize(subtract(get_light(env)->position, hit_point)), env->objects, &distance2);
	return (distance2 < threshold);
}
