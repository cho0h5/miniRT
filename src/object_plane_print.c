/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_plane_print.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:52:12 by younghoc          #+#    #+#             */
/*   Updated: 2024/08/26 13:52:13 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "object.h"
#include "vector3.h"

void	plane_print(const t_plane *plane)
{
	printf("plane\n");
	printf("- position: ");
	vec3_print(plane->position);
	printf("\n");
	printf("- normal: ");
	vec3_print(plane->normal);
	printf("\n");
	printf("- color: ");
	vec3_print(plane->color);
	printf("\n");
}
