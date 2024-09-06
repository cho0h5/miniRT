#include "environment.h"
#include "validate.h"
#include "panic.h"

void	validate_environment(const t_environment *env)
{
	if (ft_lstsize(env->lights) != 1)
		panic("there must be exactly one light");
	if (ft_lstsize(env->cameras) != 1)
		panic("there must be exactly one camera");
	if (ft_lstsize(env->ambients) != 1)
		panic("there must be exactly one ambient");
	validate_light(get_light(env));
	validate_camera(get_camera(env));
	validate_ambient(get_ambient(env));
	ft_lstiter(env->objects, validate_object);
}
