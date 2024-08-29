/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_cylinder_color.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:51:54 by younghoc          #+#    #+#             */
/*   Updated: 2024/08/29 15:54:15 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "object.h"
#include "color.h"

unsigned int	get_cylinder_color(const t_cylinder *cylinder,
						const t_environment *env, const t_vector3 ray,
						const double distance)
{
	(void)env;
	(void)ray;
	(void)distance;
	return (to_color(cylinder->color));
}
