/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_newline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:52:32 by younghoc          #+#    #+#             */
/*   Updated: 2024/08/26 13:52:33 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "panic.h"
#include "parse.h"

void	parse_newline(const char *line, size_t *i)
{
	skip_space(line, i);
	if (line[*i] != '\n')
		panic("failed to parse newline: unexpected character");
	(*i)++;
}
