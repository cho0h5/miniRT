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

	if (keycode == KEY_Q)
		get_camera(env)->position.z -= 10;
	else if (keycode == KEY_E)
		get_camera(env)->position.z += 10;
	else if (keycode == KEY_W)
		get_camera(env)->position = add(pos, scale(dir, 10));
	else if (keycode == KEY_S)
		get_camera(env)->position = add(pos, scale(dir, -10));
	else if (keycode == KEY_A)
		get_camera(env)->position = add(pos, scale(normalize(cross(vector3(0, 0, 1), dir)), 10));
	else if (keycode == KEY_D)
		get_camera(env)->position = add(pos, scale(normalize(cross(vector3(0, 0, 1), dir)), -10));
	else
		panic("failed to move camera: unexpected key");
}

#include <stdio.h>
static void	rotate_camera(int keycode, t_environment *env)
{
printf("key: %d\n", keycode);
	const t_vector3	dir = get_camera(env)->orientation;

	if (keycode == KEY_UP)
		panic("unimplemented");
	else if (keycode == KEY_DOWN)
		panic("unimplemented");
	else if (keycode == KEY_LEFT)
		get_camera(env)->orientation = rotate2(vector3(0, 0, 1), 10.0 / 180 * M_PI, dir);
	else if (keycode == KEY_RIGHT)
		get_camera(env)->orientation = rotate2(vector3(0, 0, 1), -10.0 / 180 * M_PI, dir);
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
