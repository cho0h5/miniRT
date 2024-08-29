/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_to_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 11:19:26 by younghoc          #+#    #+#             */
/*   Updated: 2024/08/29 13:45:37 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "vector3.h"

unsigned int	to_color(const t_vector3 vec)
{
	unsigned int	color;

	color = 0;
	color += (unsigned char) fmin(255, fmax(0, vec.x));
	color = color << 8;
	color += (unsigned char) fmin(255, fmax(0, vec.y));
	color = color << 8;
	color += (unsigned char) fmin(255, fmax(0, vec.z));
	return (color);
}
