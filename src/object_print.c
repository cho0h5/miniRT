#include "object.h"
#include "panic.h"

void	object_print(const t_object_category *object_category)
{
	const void	*object = (void *)object_category + sizeof(t_object_category);

	if (*object_category == OBJ_PLANE)
		plane_print(object);
	else if (*object_category == OBJ_SPHERE)
		sphere_print(object);
	else if (*object_category == OBJ_CYLINDER)
		cylinder_print(object);
	else
		panic("failed to print object: unexpected category\n");
}
