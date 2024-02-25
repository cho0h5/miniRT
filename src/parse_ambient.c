#include <stdlib.h>
#include "libft.h"
#include "object.h"
#include "panic.h"
#include "parse.h"

static t_list	*create_ambient_node(t_ambient *ambient)
{
	t_list		*node;

	node = ft_lstnew(ambient);
	if (node == NULL)
		panic("failed to malloc");
	return (node);
}

void	parse_ambient(t_list **ambients, const char *line, size_t *i)
{
	t_ambient	*ambient;
	t_list		*node;

	ambient = malloc(sizeof(t_ambient));
	if (ambient == NULL)
		panic("failed to malloc");
	parse_decimal(&ambient->ratio, line, i);
	parse_vector3(&ambient->color, line, i);
	parse_newline(line, i);
	node = create_ambient_node(ambient);
	ft_lstadd_back(ambients, node);
}
