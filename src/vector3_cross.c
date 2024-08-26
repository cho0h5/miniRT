/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_cross.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:52:52 by younghoc          #+#    #+#             */
/*   Updated: 2024/08/26 13:52:53 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"

t_vector3	cross(const t_vector3 vec1, const t_vector3 vec2)
{
	t_vector3	cross_product;

	cross_product.x = (vec1.y * vec2.z) - (vec1.z * vec2.y);
	cross_product.y = (vec1.z * vec2.x) - (vec1.x * vec2.z);
	cross_product.z = (vec1.x * vec2.y) - (vec1.y * vec2.x);
	return (cross_product);
}
