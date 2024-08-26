/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_pixel_to_ray.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:52:45 by younghoc          #+#    #+#             */
/*   Updated: 2024/08/26 21:05:20 by younghoc         ###   ########.fr       */
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
	return (normalize(ray));
}

static double	camera_latitude(const t_vector3 camera_orientation)
{
	const double	x = sqrt(camera_orientation.x * camera_orientation.x
		+ camera_orientation.y * camera_orientation.y);
	return (atan2(camera_orientation.z, x));
}

static double	camera_longitude(const t_vector3 camera_orientation)
{
	return (atan2(camera_orientation.y, camera_orientation.x) - M_PI / 2);
}

t_vector3	pixel_to_ray(const t_camera *camera, int i, int j)
{
	const t_vector3	normalized_ray = get_normalized_ray(camera->fov, i, j);
	const double	theta1 = camera_latitude(camera->orientation);
	const double	theta2 = camera_longitude(camera->orientation);
	const t_vector3 tmp1 = rotate2(vector3(1, 0, 0), theta1, normalized_ray);
	const t_vector3 tmp2 = rotate2(vector3(0, 0, 1), theta2, tmp1);

	return (tmp2);
}
