/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_ambient_print.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:51:51 by younghoc          #+#    #+#             */
/*   Updated: 2024/08/26 13:51:52 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "object.h"

void	ambient_print(const t_ambient *ambient)
{
	printf("ambient\n");
	printf("- ratio: %.2f\n", ambient->ratio);
	printf("- color: ");
	vec3_print(ambient->color);
	printf("\n");
}
