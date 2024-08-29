/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_cylinder_color.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:51:54 by younghoc          #+#    #+#             */
/*   Updated: 2024/08/29 11:25:00 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

unsigned int	get_cylinder_color(const t_cylinder *cylinder,
						const t_light *light)
{
	(void)light;
	return (to_uint(cylinder->color));
}
