#include "libft.h"
#include "object.h"
#include "parse.h"
#include "panic.h"

void	parse_cylinder(t_list **objects, const char *line, size_t *i)
{
	t_object_category	*category;
	t_cylinder			*cylinder;
	t_list				*node;

	category = malloc(sizeof(t_object_category) + sizeof(t_cylinder));
	if (category == NULL)
		panic("failed to malloc");
	*category = OBJ_CYLINDER;
	cylinder = (t_cylinder *)((void *)category + sizeof(t_object_category));
	parse_vector3(&cylinder->position, line, i);
	parse_vector3(&cylinder->axis, line, i);
	parse_decimal(&cylinder->diameter, line, i);
	parse_decimal(&cylinder->height, line, i);
	parse_vector3(&cylinder->color, line, i);
	parse_newline(line, i);
	node = ft_lstnew(category);
	if (node == NULL)
		panic("failed to malloc");
	ft_lstadd_back(objects, node);
}
