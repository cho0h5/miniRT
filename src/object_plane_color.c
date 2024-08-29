/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_plane_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:52:09 by younghoc          #+#    #+#             */
/*   Updated: 2024/08/29 11:21:31 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

unsigned int	get_plane_color(const t_plane *plane,
						const t_light *light)
{
	(void)light;
	return (to_uint(plane->color));
}
