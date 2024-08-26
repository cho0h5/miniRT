/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_light_print.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:52:08 by younghoc          #+#    #+#             */
/*   Updated: 2024/08/26 13:52:09 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "object.h"
#include "vector3.h"

void	light_print(const t_light *light)
{
	printf("light\n");
	printf("- position: ");
	vec3_print(light->position);
	printf("\n");
	printf("- brightness: %.2f\n", light->brightness);
	printf("- color: ");
	vec3_print(light->color);
	printf("\n");
}
