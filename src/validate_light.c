/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 19:43:29 by younghoc          #+#    #+#             */
/*   Updated: 2024/09/06 19:43:30 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

void	validate_light(const t_light *light)
{
	validate_range(0, 1, light->brightness);
	validate_color(light->color);
}
