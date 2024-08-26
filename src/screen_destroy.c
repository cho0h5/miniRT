/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:52:42 by younghoc          #+#    #+#             */
/*   Updated: 2024/08/26 13:52:43 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "environment.h"
#include "screen.h"

int	destroy_screen(t_environment *env)
{
	mlx_destroy_image(env->mlx, env->image.image);
	mlx_destroy_window(env->mlx, env->mlx_window);
	exit(0);
	return (0);
}
