/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation_closest_point_on_skew_lines.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 19:20:29 by younghoc          #+#    #+#             */
/*   Updated: 2024/08/26 19:35:30 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "equation.h"

double	closest_point_on_skew_lines(const t_vector3 a1, const t_vector3 b1,
		const t_vector3 a2, const t_vector3 b2)
{
	const t_vector3	a2a1 = subtract(a1, a2);
	const double	b1square = dot(b1, b1);
	const double	b2square = dot(b2, b2);
	const double	b1b2 = dot(b1, b2);

	return ((dot(a2a1, b2) * b1b2 - dot(a2a1, b1) * b2square)
		/ (b1square * b2square - b1b2 * b1b2));
}
