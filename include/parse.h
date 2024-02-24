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
char			*parse_word(const char *line, size_t *i);
t_identifier	parse_identifier(char *line, size_t *i);
void			parse_ambient(t_list **ambients);
void			parse_camera(t_list **cameras);
void			parse_light(t_list **lights);
void			parse_object(t_list **objects);

void			skip_space(char *line, size_t *i);

#endif
