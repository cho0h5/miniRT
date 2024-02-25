#include "libft.h"
#include "object.h"
#include "panic.h"
#include "parse.h"

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
	node = ft_lstnew(ambient);
	if (node == NULL)
		panic("failed to malloc");
	ft_lstadd_back(ambients, node);
}
