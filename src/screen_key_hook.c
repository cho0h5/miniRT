#include <mlx.h>
#include "screen.h"
#include "environment.h"
#include "vector3.h"

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
}

#include <stdio.h>
int	key_hook(int keycode, t_environment *env)
{
	printf("key: %d\n", keycode);
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
