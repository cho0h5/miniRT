/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:45:32 by younghoc          #+#    #+#             */
/*   Updated: 2024/02/19 15:45:34 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

#include "libft.h"
#include "vector3.h"

typedef struct s_ambient
{
	double		ratio;
	t_vector3	color;
}	t_ambient;

typedef struct s_camera
{
	t_vector3	position;
	t_vector3	orientation;
	double		fov;
}	t_camera;

typedef struct s_light
{
	t_vector3	position;
	double		brightness;
	t_vector3	color;
}	t_light;

typedef enum e_object_category
{
	OBJ_PLANE,
	OBJ_SPHERE,
	OBJ_CYLINDER,
}	t_object_category;

typedef struct s_plane
{
	t_vector3	position;
	t_vector3	normal;
	t_vector3	color;
}	t_plane;

typedef struct s_sphere
{
	t_vector3	position;
	double		diameter;
	t_vector3	color;
}	t_sphere;

typedef struct s_cylinder
{
	t_vector3	position;
	t_vector3	axis;
	double		diameter;
	double		height;
	t_vector3	color;
}	t_cylinder;

void				ambient_print(const t_ambient *ambient);
void				camera_print(const t_camera *camera);
void				light_print(const t_light *light);
void				object_print(const t_object_category *object_category);
void				plane_print(const t_plane *plane);
void				sphere_print(const t_sphere *sphere);
void				cylinder_print(const t_cylinder *cylinder);

t_rotate_info		init_rotate_info(const t_camera *camera);

t_object_category	*get_closest_object(const t_vector3 pos, const t_vector3 ray, t_list *objects);
double				object_distance(const t_vector3 pos, const t_vector3 ray, t_object_category *object);
double				plane_distance(const t_vector3 pos, const t_vector3 ray, t_object_category *object);
double				sphere_distance(const t_vector3 pos, const t_vector3 ray, t_object_category *object);
double				cylinder_distance(const t_vector3 pos, const t_vector3 ray, t_object_category *object);

unsigned int		get_object_color(const t_object_category *object);
unsigned int		get_plane_color(const t_plane *plane);
unsigned int		get_sphere_color(const t_sphere *sphere);
unsigned int		get_cylinder_color(const t_cylinder *cylinder);

#endif
