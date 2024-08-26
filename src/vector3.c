/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:53:01 by younghoc          #+#    #+#             */
/*   Updated: 2024/08/26 13:53:02 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"

t_vector3	vector3(double x, double y, double z)
{
	t_vector3	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}
