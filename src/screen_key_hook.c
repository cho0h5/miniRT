#include <mlx.h>
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

int	key_hook(int keycode, t_environment *env)
{
	if (keycode == KEY_ESC)
		destroy_screen(env);
	else if (keycode == KEY_Q
		|| keycode == KEY_W
		|| keycode == KEY_E
		|| keycode == KEY_A
		|| keycode == KEY_S
		|| keycode == KEY_D)
		move_camera(keycode, env);
//	else if (keycode == 123)
//		env->x -= 100 / env->zoom / 1080 * 4;
//	else if (keycode == 124)
//		env->x += 100 / env->zoom / 1080 * 4;
//	else if (keycode == 125)
//		env->y -= 100 / env->zoom / 1080 * 4;
//	else if (keycode == 126)
//		env->y += 100 / env->zoom / 1080 * 4;
//	else if (18 <= keycode && keycode <= 20)
//		env->color = (keycode - 18) % 3;
	draw(env);
	return (0);
}
