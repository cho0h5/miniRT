#include "libft.h"
#include "object.h"
#include "panic.h"
#include "parse.h"

void	parse_camera(t_list **cameras, const char *line, size_t *i)
{
	t_camera	*camera;
	t_list		*node;

	camera = malloc(sizeof(t_camera));
	if (camera == NULL)
		panic("failed to malloc");
	parse_vector3(&camera->position, line, i);
	parse_vector3(&camera->orientation, line, i);
	parse_decimal(&camera->fov, line, i);
	parse_newline(line, i);
	node = ft_lstnew(camera);
	if (node == NULL)
		panic("failed to malloc");
	ft_lstadd_back(cameras, node);
}
