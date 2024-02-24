#include "parse.h"

void	skip_space(char *line, size_t *i)
{
	while (line[*i] != '\0' && ft_strchr(" \t", line[*i]) != NULL)
		(*i)++;
}

