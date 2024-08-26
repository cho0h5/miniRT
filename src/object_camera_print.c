/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_camera_print.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:51:52 by younghoc          #+#    #+#             */
/*   Updated: 2024/08/26 13:51:53 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "object.h"
#include "vector3.h"

void	camera_print(const t_camera *camera)
{
	printf("camera\n");
	printf("- position: ");
	vec3_print(camera->position);
	printf("\n");
	printf("- orientation: ");
	vec3_print(camera->orientation);
	printf("\n");
	printf("- fov: %.2f\n", camera->fov);
}
