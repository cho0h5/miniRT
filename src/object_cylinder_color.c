/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_cylinder_color.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:51:54 by younghoc          #+#    #+#             */
/*   Updated: 2024/08/29 20:06:41 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "object.h"
#include "color.h"

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
	(void)cylinder;
	(void)env;
	(void)ray;
	(void)distance;
	const t_vector3	asdf = vector3(0, 0, 0);
	return (asdf);
}

unsigned int	get_cylinder_color(const t_cylinder *cylinder,
						const t_environment *env, const t_vector3 ray,
						const double distance)
{
	const t_vector3	ambient = get_cylinder_ambient(cylinder, get_ambient(env));
	const t_vector3	diffuse = get_cylinder_diffuse(cylinder, env, ray, distance);

	if (is_shadow(env, ray, distance))
		return (to_color(ambient));
	else
		return (to_color(add(ambient, diffuse)));
}
