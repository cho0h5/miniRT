/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_scale.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:52:58 by younghoc          #+#    #+#             */
/*   Updated: 2024/08/26 13:52:59 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"

t_vector3	scale(const t_vector3 vec, double a)
{
	t_vector3	result;

	result.x = vec.x * a;
	result.y = vec.y * a;
	result.z = vec.z * a;
	return (result);
}
