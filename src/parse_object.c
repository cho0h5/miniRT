#include "libft.h"
#include "parse.h"
#include "panic.h"

void	parse_object(t_list **objects, const char *line, size_t *i, t_identifier id)
{
	if (id == ID_PLANE)
		parse_plane(objects, line, i);
	else if (id == ID_SPHERE)
		parse_sphere(objects, line, i);
	else if (id == ID_CYLINDER)
		parse_cylinder(objects, line, i);
	else
		panic("failed to parse object: unexpected identifier\n");
}
