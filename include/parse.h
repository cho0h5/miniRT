#ifndef PARSE_H
# define PARSE_H

#include "environment.h"

typedef enum e_identifier
{
	ID_AMBIENT,
	ID_CAMERA,
	ID_LIGHT,
	ID_SPHERE,
	ID_PLANE,
	ID_CYLINDER
}	t_identifier;

void			parse(t_environment *env, char *filename);
void			parse_line(t_environment *env, char *line);
t_identifier	parse_identifier(char *line, int *i);

#endif
