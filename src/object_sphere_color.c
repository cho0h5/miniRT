/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_sphere_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:52:17 by younghoc          #+#    #+#             */
/*   Updated: 2024/08/29 12:53:25 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "object.h"
#include "color.h"

unsigned int	get_sphere_color(const t_sphere *sphere,
						const t_environment *env, const double distance)
{
	(void)env;
	(void)distance;
	return (to_uint(sphere->color));
}
