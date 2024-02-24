#include "libft.h"
#include "panic.h"
#include "parse.h"

t_identifier	parse_identifier(char *line, size_t *i)
{
	char			*word;
	t_identifier	id;

	skip_space(line, i);
	id = ID_AMBIENT;
	word = parse_word(line, i);
	if (ft_strncmp(word, "A", 2))
		id = ID_AMBIENT;
	else if (ft_strncmp(word, "C", 2))
		id = ID_CAMERA;
	else if (ft_strncmp(word, "L", 2))
		id = ID_LIGHT;
	else if (ft_strncmp(word, "pl", 3))
		id = ID_SPHERE;
	else if (ft_strncmp(word, "sp", 3))
		id = ID_PLANE;
	else if (ft_strncmp(word, "cy", 3))
		id = ID_CYLINDER;
	else
		panic("unhandled identifier");
	free(word);
	return (id);
}
