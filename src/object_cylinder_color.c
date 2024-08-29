/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_cylinder_color.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:51:54 by younghoc          #+#    #+#             */
/*   Updated: 2024/08/29 20:03:53 by younghoc         ###   ########.fr       */
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

unsigned int	get_cylinder_color(const t_cylinder *cylinder,
						const t_environment *env, const t_vector3 ray,
						const double distance)
{
	const t_vector3	ambient = get_cylinder_ambient(cylinder, get_ambient(env));

	(void)ray;
	(void)distance;
	return (to_color(ambient));
}
