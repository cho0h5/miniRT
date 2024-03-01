#include <mlx.h>
#include "environment.h"
#include "screen.h"

int	destroy_screen(t_environment *env)
{
	mlx_destroy_image(env->mlx, env->image.image);
	mlx_destroy_window(env->mlx, env->mlx_window);
	exit(0);
	return (0);
}
