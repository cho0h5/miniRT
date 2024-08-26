/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_pixel_to_ray.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:52:45 by younghoc          #+#    #+#             */
/*   Updated: 2024/08/26 13:52:46 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "screen.h"
#include "vector3.h"

static t_vector3	get_normalized_ray(double fov, int i, int j)
{
	const double	dx = tan((fov / 2) * (M_PI / 180)) / ((double)WIDTH / 2);
	t_vector3		ray;

	ray.x = (i - (double)WIDTH / 2) * dx;
	ray.y = 1;
	ray.z = ((double)WIDTH / 2 - j) * dx;
	return (ray);
}

t_vector3	pixel_to_ray(const t_camera *camera, const t_rotate_info *info,
				int i, int j)
{
	t_vector3	normalized_ray;

	normalized_ray = get_normalized_ray(camera->fov, i, j);
	return (rotate(info, normalized_ray));
}
