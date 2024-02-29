#include "environment.h"
#include "libft.h"
#include "object.h"
#include "panic.h"
#include "parse.h"

int	main(int argc, char **argv)
{
	t_environment	env;

	if (argc != 2)
		panic("invalid argument");
	init_environment(&env);
	parse(&env, argv[1]);


	// for debug
	ambient_print(env.ambients->content);
	camera_print(env.cameras->content);
	light_print(env.lights->content);
	t_list	*node;
	node = env.objects;
	while (node) {
		object_print(node->content);
		node = node->next;
	}
}
