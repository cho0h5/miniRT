/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:51:48 by younghoc          #+#    #+#             */
/*   Updated: 2024/08/26 13:51:49 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "environment.h"
#include "screen.h"

void	init_environment(t_environment *env)
{
	env->lights = NULL;
	env->cameras = NULL;
	env->ambients = NULL;
	env->objects = NULL;
	env->mlx = mlx_init();
	env->mlx_window = mlx_new_window(env->mlx,
			WIDTH, WIDTH, "miniRT");
	env->image.image = mlx_new_image(env->mlx, WIDTH, WIDTH);
	env->image.address = mlx_get_data_addr(env->image.image,
			&env->image.bits_per_pixel, &env->image.line_length,
			&env->image.endian);
}
