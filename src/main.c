#include <mlx.h>
#include "environment.h"
#include "panic.h"
#include "parse.h"
#include "screen.h"

int	main(int argc, char **argv)
{
	t_environment	env;

	if (argc != 2)
		panic("invalid argument");
	init_environment(&env);
	parse(&env, argv[1]);
	draw(&env);
	mlx_key_hook(env.mlx_window, key_hook, &env);
	mlx_hook(env.mlx_window, ON_DESTROY, 0, destroy_screen, &env);
	mlx_loop(env.mlx);
}
