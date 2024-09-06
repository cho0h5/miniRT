/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_ambient.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 19:43:24 by younghoc          #+#    #+#             */
/*   Updated: 2024/09/06 19:43:25 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

void	validate_ambient(const t_ambient *ambient)
{
	validate_range(0, 1, ambient->ratio);
	validate_color(ambient->color);
}
