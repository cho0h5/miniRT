/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_cylinder_color.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:51:54 by younghoc          #+#    #+#             */
/*   Updated: 2024/08/26 13:51:55 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

unsigned int	get_cylinder_color(const t_cylinder *cylinder)
{
	unsigned int	color;

	color = 0;
	color += (unsigned char)cylinder->color.x;
	color = color << 8;
	color += (unsigned char)cylinder->color.y;
	color = color << 8;
	color += (unsigned char)cylinder->color.z;
	return (color);
}
