/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:52:42 by younghoc          #+#    #+#             */
/*   Updated: 2024/09/06 20:05:30 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "environment.h"
#include "screen.h"

int	destroy_screen(t_environment *env)
{
	free_environment(env);
	exit(0);
	return (0);
}
