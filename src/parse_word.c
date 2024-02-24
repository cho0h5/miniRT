#include <stdlib.h>
#include "libft.h"
#include "vector_char.h"

char	*parse_word(const char *line, size_t *i)
{
	t_vector_char	vector;

	init_vector_char(&vector);
	while (line[*i] != '\0' && ft_strchr(" \t,", line[*i]) == NULL)
		push_back_char(&vector, line[(*i)++]);
	push_back_char(&vector, '\0');
	return (vector.data);
}
