#include "libft.h"
#include "parse.h"
#include <environment.h>

static void	skip_space(char *line, int *i)
{
	while (line[*i] != 0 && ft_strchr(" \t", line[*i]) != NULL)
		(*i)++;
}

void	parse_line(t_environment *env, char *line)
{
	int				i;
	t_identifier	id;

	i = 0;
	skip_space(line, &i);
	id = parse_identifier(line, &i);
	if (id == ID_AMBIENT)
		parse_embient();
	else if (id == ID_CAMERA)
		parse_camera();
	else if (id == ID_LIGHT)
		parse_light();
	else
		parse_object();
}
