/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_key_hook.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:52:45 by younghoc          #+#    #+#             */
/*   Updated: 2024/08/26 15:03:59 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <mlx.h>
#include "object.h"
#include "screen.h"
#include "environment.h"
#include "vector3.h"
#include "panic.h"

static void	move_camera(int keycode, t_environment *env)
{
	const t_vector3	pos = get_camera(env)->position;
	const t_vector3	dir = get_camera(env)->orientation;
	t_camera		*camera;

	camera = get_camera(env);
	if (keycode == KEY_Q)
		camera->position.z -= 10;
	else if (keycode == KEY_E)
		camera->position.z += 10;
	else if (keycode == KEY_W)
		camera->position = add(pos, scale(dir, 10));
	else if (keycode == KEY_S)
		camera->position = add(pos, scale(dir, -10));
	else if (keycode == KEY_A)
		camera->position = add(pos,
				scale(normalize(cross(vector3(0, 0, 1), dir)), 10));
	else if (keycode == KEY_D)
		camera->position = add(pos,
				scale(normalize(cross(vector3(0, 0, 1), dir)), -10));
	else
		panic("failed to move camera: unexpected key");
}

static void	rotate_camera(int keycode, t_environment *env)
{
	const t_vector3	dir = get_camera(env)->orientation;
	t_camera		*camera;

	camera = get_camera(env);
	if (keycode == KEY_UP)
		camera->orientation = rotate2(normalize(
					cross(dir, vector3(0, 0, 1))), 10.0 / 180 * M_PI, dir);
	else if (keycode == KEY_DOWN)
		camera->orientation = rotate2(normalize(
					cross(dir, vector3(0, 0, 1))), -10.0 / 180 * M_PI, dir);
	else if (keycode == KEY_LEFT)
		camera->orientation = rotate2(vector3(0, 0, 1),
				10.0 / 180 * M_PI, dir);
	else if (keycode == KEY_RIGHT)
		camera->orientation = rotate2(vector3(0, 0, 1),
				-10.0 / 180 * M_PI, dir);
}

int	key_hook(int keycode, t_environment *env)
{
	if (keycode == KEY_ESC)
		destroy_screen(env);
	else if (keycode == KEY_Q || keycode == KEY_E
		|| keycode == KEY_W || keycode == KEY_S
		|| keycode == KEY_A || keycode == KEY_D)
		move_camera(keycode, env);
	else if (keycode == KEY_UP || keycode == KEY_DOWN
		|| keycode == KEY_LEFT || keycode == KEY_RIGHT)
		rotate_camera(keycode, env);
	draw(env);
	return (0);
}
