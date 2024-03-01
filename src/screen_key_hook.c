#include <mlx.h>
#include "screen.h"
#include "environment.h"

int	key_hook(int keycode, t_environment *env)
{
	if (keycode == 53)
		destroy_screen(env);
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
	return (0);
}
