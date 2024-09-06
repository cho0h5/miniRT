/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:51:50 by younghoc          #+#    #+#             */
/*   Updated: 2024/09/06 19:02:49 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "environment.h"
#include "panic.h"
#include "parse.h"
#include "screen.h"
#include "validate.h"

int	main(int argc, char **argv)
{
	t_environment	env;

	if (argc != 2)
		panic("invalid argument");
	init_environment(&env);
	parse(&env, argv[1]);
	validate_environment(&env);
	draw(&env);
	mlx_key_hook(env.mlx_window, key_hook, &env);
	mlx_hook(env.mlx_window, ON_DESTROY, 0, destroy_screen, &env);
	mlx_loop(env.mlx);
}
