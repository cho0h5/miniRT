/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_sphere_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:52:17 by younghoc          #+#    #+#             */
/*   Updated: 2024/08/26 13:52:18 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

unsigned int	get_sphere_color(const t_sphere *sphere)
{
	unsigned int	color;

	color = 0;
	color += (unsigned char)sphere->color.x;
	color = color << 8;
	color += (unsigned char)sphere->color.y;
	color = color << 8;
	color += (unsigned char)sphere->color.z;
	return (color);
}
