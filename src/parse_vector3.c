/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vector3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:52:37 by younghoc          #+#    #+#             */
/*   Updated: 2024/08/26 13:52:38 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	parse_vector3(t_vector3 *vec, const char *line, size_t *i)
{
	parse_decimal(&vec->x, line, i);
	parse_comma(line, i);
	parse_decimal(&vec->y, line, i);
	parse_comma(line, i);
	parse_decimal(&vec->z, line, i);
	skip_space(line, i);
}
