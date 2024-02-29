#include "libft.h"
#include "object.h"
#include "parse.h"
#include "panic.h"

void	parse_sphere(t_list **objects, const char *line, size_t *i)
{
	t_object_category	*category;
	t_sphere			*sphere;
	t_list				*node;

	category = malloc(sizeof(t_object_category) + sizeof(t_sphere));
	if (category == NULL)
		panic("failed to malloc");
	*category = OBJ_SPHERE;
	sphere = (t_sphere *)((void *)category + sizeof(t_object_category));
	parse_vector3(&sphere->position, line, i);
	parse_decimal(&sphere->diameter, line, i);
	parse_vector3(&sphere->color, line, i);
	parse_newline(line, i);
	node = ft_lstnew(sphere);
	if (node == NULL)
		panic("failed to malloc");
	ft_lstadd_back(objects, node);
}
