/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_to_uint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 11:19:26 by younghoc          #+#    #+#             */
/*   Updated: 2024/08/29 11:23:10 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"

unsigned int	to_uint(const t_vector3 vec)
{
	unsigned int	color;

	color = 0;
	color += (unsigned char) vec.x;
	color = color << 8;
	color += (unsigned char) vec.y;
	color = color << 8;
	color += (unsigned char) vec.z;
	return (color);
}
