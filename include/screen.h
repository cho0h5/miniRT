/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:53:44 by younghoc          #+#    #+#             */
/*   Updated: 2024/08/26 13:53:45 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCREEN_H
# define SCREEN_H

# include "environment.h"
# include "vector3.h"
# include "object.h"

# define WIDTH 720
# define ON_DESTROY 17

# define KEY_ESC 53
# define KEY_Q 12
# define KEY_W 13
# define KEY_E 14
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124

t_vector3	pixel_to_ray(const t_camera *camera, const t_rotate_info *info, int i, int j);
void		draw(t_environment *env);
int			destroy_screen(t_environment *env);
int			key_hook(int keycode, t_environment *env);

#endif
