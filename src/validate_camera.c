/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 19:43:26 by younghoc          #+#    #+#             */
/*   Updated: 2024/09/06 19:43:27 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

void	validate_camera(const t_camera *camera)
{
	validate_orientation(&camera->orientation);
	validate_range(1, 180, camera->fov);
}
