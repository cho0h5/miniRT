/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_plane_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:52:09 by younghoc          #+#    #+#             */
/*   Updated: 2024/08/29 13:41:39 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

unsigned int	get_plane_color(const t_plane *plane,
						const t_environment *env, const double distance)
{
	const t_vector3	ambient = get_plane_ambient(plane, get_ambient(env));
	const t_vector3	hit_point = add(get_camera(env)->position,
			scale(get_camera(env)->orientation, distance));

	(void)hit_point;
	return (to_uint(ambient));
}
