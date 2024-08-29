/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_sphere_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:52:17 by younghoc          #+#    #+#             */
/*   Updated: 2024/08/29 13:13:37 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "object.h"
#include "color.h"
#include "vector3.h"

static t_vector3	get_sphere_ambient(const t_sphere *sphere, const t_ambient *ambient)
{
	return (multiply(sphere->color, scale(ambient->color, ambient->ratio / 255)));
}

unsigned int	get_sphere_color(const t_sphere *sphere,
						const t_environment *env, const double distance)
{
	const t_vector3	ambient = get_sphere_ambient(sphere, get_ambient(env));

	(void)distance;
	return (to_uint(ambient));
}
