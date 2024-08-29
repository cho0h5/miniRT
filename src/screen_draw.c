/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:52:44 by younghoc          #+#    #+#             */
/*   Updated: 2024/08/29 12:34:47 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "environment.h"
#include "object.h"
#include "screen.h"
#include "vector3.h"
#include "color.h"

static void	put_mlx_pixel(t_mlx_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->address
		+ (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw(t_environment *env)
{
	t_vector3			ray;
	t_object_category	*object;
	int					j;
	int					i;
	double				distance;

	j = 0;
	while (j < WIDTH)
	{
		i = 0;
		while (i < WIDTH)
		{
			ray = pixel_to_ray(env->cameras->content, i, j);
			object = get_closest_object(get_camera(env)->position, ray,
					env->objects, &distance);
			if (object == NULL)
				put_mlx_pixel(&env->image, i, j, 0);
			else
				put_mlx_pixel(&env->image, i, j,
					get_object_color(object, env));
			i += 1;
		}
		j += 1;
	}
	mlx_put_image_to_window(env->mlx, env->mlx_window, env->image.image, 0, 0);
}
