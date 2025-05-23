/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_comma.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:52:23 by younghoc          #+#    #+#             */
/*   Updated: 2024/08/26 13:52:24 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "panic.h"
#include "parse.h"

void	parse_comma(const char *line, size_t *i)
{
	if (line[*i] == '\0')
		panic("failed to parse comma: unexpected newline");
	if (line[*i] != ',')
		panic("failed to parse comma: unexpected character");
	(*i)++;
	skip_space(line, i);
}
