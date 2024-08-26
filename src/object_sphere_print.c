/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_sphere_print.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:52:19 by younghoc          #+#    #+#             */
/*   Updated: 2024/08/26 13:52:20 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "object.h"

void	sphere_print(const t_sphere *sphere)
{
	printf("sphere\n");
	printf("- position: ");
	vec3_print(sphere->position);
	printf("\n");
	printf("- diameter: %.2f\n", sphere->diameter);
	printf("- color: ");
	vec3_print(sphere->color);
	printf("\n");
}
