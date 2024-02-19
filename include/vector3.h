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

s_vector3	vector3(double x, double y, double z);
double		magnitude(const t_vector3 vec);
s_vector3	normalize(const t_vector3 vec);

#endif
