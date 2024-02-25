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
