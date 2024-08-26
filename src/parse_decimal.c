/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:52:26 by younghoc          #+#    #+#             */
/*   Updated: 2024/08/26 13:52:27 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "panic.h"
#include "parse.h"

static int	parse_sign(const char *line, size_t *i)
{
	if (ft_isdigit(line[*i]) || line[*i] == '.')
		return (1);
	if (line[*i] == '+')
	{
		(*i)++;
		return (1);
	}
	if (line[*i] == '-')
	{
		(*i)++;
		return (-1);
	}
	panic("failed to parse sign");
	return (0);
}

static int	parse_decimal_point(const char *line, size_t *i)
{
	if (line[*i] == '.')
	{
		(*i)++;
		return (1);
	}
	return (0);
}

static void	parse_decimal_integer_part(double *decimal, const char *line,
				size_t *i)
{
	while (ft_isdigit(line[*i]))
	{
		*decimal += line[*i] - '0';
		(*i)++;
		if (ft_isdigit(line[*i]))
			*decimal *= 10;
	}
}

static void	parse_decimal_fractional_part(double *decimal, const char *line,
				size_t *i)
{
	double	scale;

	scale = 0.1;
	while (ft_isdigit(line[*i]))
	{
		*decimal += (line[*i] - '0') * scale;
		scale /= 10;
		(*i)++;
	}
}

void	parse_decimal(double *decimal, const char *line, size_t *i)
{
	int	sign;

	*decimal = 0;
	sign = parse_sign(line, i);
	parse_decimal_integer_part(decimal, line, i);
	if (parse_decimal_point(line, i))
		parse_decimal_fractional_part(decimal, line, i);
	*decimal *= sign;
	skip_space(line, i);
}
