/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 19:43:06 by younghoc          #+#    #+#             */
/*   Updated: 2024/09/06 19:43:58 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_H
# define VALIDATE_H

# include "environment.h"

void	validate_environment(const t_environment *env);

void	validate_light(const t_light *light);
void	validate_camera(const t_camera *camera);
void	validate_ambient(const t_ambient *ambient);
void	validate_object(void *content);

void	validate_range(const double mininum, const double maximum,
			const double x);
void	validate_positive(const double x);
void	validate_orientation(const t_vector3 *orientation);
void	validate_color(const t_vector3 color);

#endif
