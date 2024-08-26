/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_dot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:52:53 by younghoc          #+#    #+#             */
/*   Updated: 2024/08/26 13:52:54 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"

double	dot(const t_vector3 vec1, const t_vector3 vec2)
{
	double	dot_product;

	dot_product = 0;
	dot_product += vec1.x * vec2.x;
	dot_product += vec1.y * vec2.y;
	dot_product += vec1.z * vec2.z;
	return (dot_product);
}
