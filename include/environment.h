/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:53:38 by younghoc          #+#    #+#             */
/*   Updated: 2024/08/26 13:53:39 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

#include "libft.h"
#include "object.h"

typedef struct s_mlx_image
{
	void	*image;
	char	*address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_mlx_image;

typedef struct s_environment
{
	t_list		*lights;
	t_list		*cameras;
	t_list		*ambients;
	t_list		*objects;
	void		*mlx;
	void		*mlx_window;
	t_mlx_image	image;
}	t_environment;

void		init_environment(t_environment *env);

t_camera	*get_camera(const t_environment *env);

#endif
