#include "vector_char.h"
#include "libft.h"

char	*push_str_back(t_vector_char *vector, char *str)
{
	const size_t	strlen = ft_strlen(str);
	size_t			i;

	i = 0;
	while (i < strlen)
	{
		push_back_char(vector, str[i]);
		i++;
	}
	return (vector->data);
}
