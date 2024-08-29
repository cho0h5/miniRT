/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_plane_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:52:09 by younghoc          #+#    #+#             */
/*   Updated: 2024/08/29 12:34:34 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "object.h"
#include "color.h"

unsigned int	get_plane_color(const t_plane *plane,
						const t_environment *env)
{
	(void)env;
	return (to_uint(plane->color));
}
