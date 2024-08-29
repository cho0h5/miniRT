/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment_get_embient.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:51:42 by younghoc          #+#    #+#             */
/*   Updated: 2024/08/29 13:04:14 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

t_ambient	*get_ambient(const t_environment *env)
{
	return (env->ambients->content);
}
