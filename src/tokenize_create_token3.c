#include <stdlib.h>
#include "libft.h"
#include "vector.h"

char	*parse_word(const char *line, size_t *i)
{
	t_vector	vector;

	init_vector(&vector);
	while (line[*i] != '\0' && ft_strchr(" \t,", line[*i]) == NULL)
		push_back(&vector, line[(*i)++]);
	push_back(&vector, '\0');
	return (vector.data);
}
