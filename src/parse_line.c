#include "parse.h"
#include "panic.h"
#include "environment.h"

void	parse_line(t_environment *env, const char *line)
{
	size_t			i;
	t_identifier	id;

	i = 0;
	id = parse_identifier(line, &i);
	if (id == ID_EMPTY_LINE)
		return ;
	else if (id == ID_UNKNOWN)
		panic("unknown identifier");
	else if (id == ID_AMBIENT)
		parse_ambient(&env->ambients, line, &i);
	else if (id == ID_CAMERA)
		parse_camera(&env->cameras, line, &i);
	else if (id == ID_LIGHT)
		parse_light(&env->lights, line, &i);
	else
		parse_object(&env->objects, line, &i);
}
