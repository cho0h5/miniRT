#include "environment.h"

t_camera	*get_camera(const t_environment *env)
{
	return (env->cameras->content);
}
