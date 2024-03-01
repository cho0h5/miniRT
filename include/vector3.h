/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:47:55 by younghoc          #+#    #+#             */
/*   Updated: 2024/02/19 15:47:56 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR3_H
# define VECTOR3_H

typedef struct s_vector3
{
	double	x;
	double	y;
	double	z;
}	t_vector3;

t_vector3	vector3(double x, double y, double z);
void		vec3_print(const t_vector3 vec);

double		magnitude(const t_vector3 vec);
t_vector3	normalize(const t_vector3 vec);

double		angle(const t_vector3 vec1, const t_vector3 vec2);
t_vector3	cross(const t_vector3 vec1, const t_vector3 vec2);
double		dot(const t_vector3 vec1, const t_vector3 vec2);

t_vector3	add(const t_vector3 vec1, const t_vector3 vec2);
t_vector3	subtract(const t_vector3 vec1, const t_vector3 vec2);
t_vector3	scale(const t_vector3 vec, double a);

#endif
