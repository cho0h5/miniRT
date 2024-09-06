/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_normalize_orientation.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 19:43:38 by younghoc          #+#    #+#             */
/*   Updated: 2024/09/06 19:43:39 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "validate.h"

void	normalize_orientation(t_vector3 *orientation)
{
	const double	mag = magnitude(*orientation);

	validate_range(0.1, 10, mag);
	orientation->x /= mag;
	orientation->y /= mag;
	orientation->z /= mag;
}
