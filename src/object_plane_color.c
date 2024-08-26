/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_plane_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:52:09 by younghoc          #+#    #+#             */
/*   Updated: 2024/08/26 13:52:10 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

unsigned int	get_plane_color(const t_plane *plane)
{
	unsigned int	color;

	color = 0;
	color += (unsigned char)plane->color.x;
	color = color << 8;
	color += (unsigned char)plane->color.y;
	color = color << 8;
	color += (unsigned char)plane->color.z;
	return (color);
}
