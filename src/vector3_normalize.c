/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_normalize.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:52:55 by younghoc          #+#    #+#             */
/*   Updated: 2024/08/26 13:52:56 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"

t_vector3	normalize(const t_vector3 vec)
{
	const double	mag = magnitude(vec);
	t_vector3		normalized;

	normalized.x = vec.x / mag;
	normalized.y = vec.y / mag;
	normalized.z = vec.z / mag;
	return (normalized);
}
