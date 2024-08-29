/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_sphere_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:52:17 by younghoc          #+#    #+#             */
/*   Updated: 2024/08/29 11:25:19 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

unsigned int	get_sphere_color(const t_sphere *sphere,
						const t_light *light)
{
	(void)light;
	return (to_uint(sphere->color));
}
