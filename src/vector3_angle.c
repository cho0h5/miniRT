/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_angle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:52:51 by younghoc          #+#    #+#             */
/*   Updated: 2024/08/26 13:52:52 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"

double	angle(const t_vector3 vec1, const t_vector3 vec2)
{
	const double	mag_vec1 = magnitude(vec1);
	const double	mag_vec2 = magnitude(vec2);
	const double	dot_product = dot(vec1, vec2);

	return (dot_product / mag_vec1 / mag_vec2);
}
