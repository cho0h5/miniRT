#include "panic.h"
#include "parse.h"

int	main(int argc, char **argv)
{
	t_environment	env;

	if (argc != 2)
		panic("invalid argument");
	parse(&env, argv[1]);
}
