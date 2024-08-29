/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:45:26 by younghoc          #+#    #+#             */
/*   Updated: 2024/08/29 19:05:35 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "environment.h"
# include "object.h"

unsigned int		get_object_color(const t_object_category *object_category,
						const t_environment *env, const t_vector3 ray,
						const double distance);
unsigned int		get_plane_color(const t_plane *plane,
						const t_environment *env, const t_vector3 ray,
						const double distance);
unsigned int		get_sphere_color(const t_sphere *sphere,
						const t_environment *env, const t_vector3 ray,
						const double distance);
unsigned int		get_cylinder_color(const t_cylinder *cylinder,
						const t_environment *env, const t_vector3 ray,
						const double distance);

int					is_shadow(const t_environment *env, const t_vector3 ray,
						const double distance);

#endif
