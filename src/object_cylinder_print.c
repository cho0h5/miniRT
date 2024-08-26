/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_cylinder_print.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:52:04 by younghoc          #+#    #+#             */
/*   Updated: 2024/08/26 13:52:05 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "object.h"
#include "vector3.h"

void	cylinder_print(const t_cylinder *cylinder)
{
	printf("cylinder\n");
	printf("- position: ");
	vec3_print(cylinder->position);
	printf("\n");
	printf("- axis: ");
	vec3_print(cylinder->axis);
	printf("\n");
	printf("- diameter: %.2f\n", cylinder->diameter);
	printf("- height: %.2f\n", cylinder->height);
	printf("- color: ");
	vec3_print(cylinder->color);
	printf("\n");
}
