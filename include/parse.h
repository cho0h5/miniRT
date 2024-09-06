/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:53:43 by younghoc          #+#    #+#             */
/*   Updated: 2024/09/06 19:36:44 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "environment.h"
# include "vector3.h"

typedef enum e_identifier
{
	ID_AMBIENT,
	ID_CAMERA,
	ID_LIGHT,
	ID_SPHERE,
	ID_PLANE,
	ID_CYLINDER,
	ID_CYLINDER_BASE,
	ID_EMPTY_LINE,
	ID_UNKNOWN
}	t_identifier;

void			parse(t_environment *env, const char *filename);
void			parse_line(t_environment *env, const char *line);
char			*parse_word(const char *line, size_t *i);
t_identifier	parse_identifier(const char *line, size_t *i);
void			parse_ambient(t_list **ambients, const char *line, size_t *i);
void			parse_camera(t_list **cameras, const char *line, size_t *i);
void			parse_light(t_list **lights, const char *line, size_t *i);
void			parse_object(t_list **objects, const char *line, size_t *i,
					t_identifier id);
void			parse_plane(t_list **objects, const char *line, size_t *i);
void			parse_sphere(t_list **objects, const char *line, size_t *i);
void			parse_cylinder(t_list **objects, const char *line, size_t *i);

void			parse_decimal(double *decimal, const char *line, size_t *i);
void			parse_vector3(t_vector3 *vec, const char *line, size_t *i);
void			parse_comma(const char *line, size_t *i);
void			parse_newline(const char *line, size_t *i);

void			skip_space(const char *line, size_t *i);

void			normalize_orientation(t_vector3 *orientation);

#endif
