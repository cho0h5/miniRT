#include "parse.h"
#include "environment.h"

void	parse_line(t_environment *env, char *line)
{
	size_t			i;
	t_identifier	id;

	i = 0;
	id = parse_identifier(line, &i);
	if (id == ID_UNKNOWN)
		return ;
	else if (id == ID_AMBIENT)
		parse_ambient(&env->ambients);
	else if (id == ID_CAMERA)
		parse_camera(&env->cameras);
	else if (id == ID_LIGHT)
		parse_light(&env->lights);
	else
		parse_object(&env->objects);
}
