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
	PLANE,
	SPHERE,
	CYLINDER,
}	t_object_category;

typedef struct s_object
{
	t_object_category	category;
	void				*content;
}	t_object;

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
}	t_sylinder;

#endif
