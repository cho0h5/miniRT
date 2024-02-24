#include "environment.h"

void	init_environment(t_environment *env)
{
	env->lights = NULL;
	env->cameras = NULL;
	env->ambients = NULL;
	env->objects = NULL;
}
