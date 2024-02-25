#include "panic.h"
#include "parse.h"

void	parse_newline(const char *line, size_t *i)
{
	skip_space(line, i);
	if (line[*i] != '\n')
		panic("failed to parse newline: unexpected character");
	(*i)++;
}
