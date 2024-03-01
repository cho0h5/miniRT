#include "environment.h"
#include "libft.h"
#include "object.h"
#include "panic.h"
#include "parse.h"
#include "screen.h"
#include "vector3.h"

int	main(int argc, char **argv)
{
	t_environment	env;

	if (argc != 2)
		panic("invalid argument");
	init_environment(&env);
	parse(&env, argv[1]);

	t_rotate_info	info = init_rotate_info(env.cameras->content);
	for (int j = 0; j < WIDTH; j++) {
		for (int i = 0; i < WIDTH; i++) {
			t_vector3 ray = pixel_to_ray(env.cameras->content, &info, i, j);
			(void)ray;
		}
	}
}
