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
	ID_CYLINDER,
	ID_UNKNOWN
}	t_identifier;

void			parse(t_environment *env, const char *filename);
void			parse_line(t_environment *env, const char *line);
char			*parse_word(const char *line, size_t *i);
t_identifier	parse_identifier(const char *line, size_t *i);
void			parse_ambient(t_list **ambients, const char *line, size_t *i);
void			parse_camera(t_list **cameras, const char *line, size_t *i);
void			parse_light(t_list **lights, const char *line, size_t *i);
void			parse_object(t_list **objects, const char *line, size_t *i);

void			skip_space(const char *line, size_t *i);

#endif
