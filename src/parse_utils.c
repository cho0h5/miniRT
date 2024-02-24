#include "parse.h"

void	skip_space(const char *line, size_t *i)
{
	while (line[*i] != '\0' && ft_strchr(" \t", line[*i]) != NULL)
		(*i)++;
}

