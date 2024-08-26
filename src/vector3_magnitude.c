/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_magnitude.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:52:54 by younghoc          #+#    #+#             */
/*   Updated: 2024/08/26 13:52:55 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "vector3.h"

double	magnitude(const t_vector3 vec)
{
	double	mag_square;

	mag_square = 0;
	mag_square += vec.x * vec.x;
	mag_square += vec.y * vec.y;
	mag_square += vec.z * vec.z;
	return (sqrt(mag_square));
}
