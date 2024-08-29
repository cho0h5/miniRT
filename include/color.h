#ifndef COLOR_H
# define COLOR_H

# include "environment.h"
# include "object.h"

unsigned int		get_object_color(const t_object_category *object_category,
						const t_environment *env);
unsigned int		get_plane_color(const t_plane *plane,
						const t_environment *env);
unsigned int		get_sphere_color(const t_sphere *sphere,
						const t_environment *env);
unsigned int		get_cylinder_color(const t_cylinder *cylinder,
						const t_environment *env);

#endif
