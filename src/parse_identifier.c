#include "parse.h"

t_identifier	parse_identifier(char *line, size_t *i)
{
	char	*identifier;
	skip_space(line, i);
	identifier = parse_word(line, i);
	return (ID_AMBIENT);
}
