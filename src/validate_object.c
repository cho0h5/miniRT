#include "validate.h"
#include "panic.h"

static void validate_plane(t_plane *plane)
{
	validate_orientation(&plane->normal);
	validate_color(plane->color);
}

static void validate_sphere(t_sphere *sphere)
{
	validate_positive(sphere->diameter);
	validate_color(sphere->color);
}

static void validate_cylinder(t_cylinder *cylinder)
{
	validate_orientation(&cylinder->axis);
	validate_positive(cylinder->diameter);
	validate_positive(cylinder->height);
	validate_color(cylinder->color);
}

static void validate_cylinder_base(t_cylinder_base *cylinder_base)
{
	validate_orientation(&cylinder_base->normal);
	validate_positive(cylinder_base->diameter);
	validate_color(cylinder_base->color);
}

void	validate_object(void *content)
{
	const t_object_category	*object_category = (t_object_category *)content;
	void	*object;

	object = (void *)object_category + sizeof(t_object_category);
	if (*object_category == OBJ_PLANE)
		validate_plane(object);
	else if (*object_category == OBJ_SPHERE)
		validate_sphere(object);
	else if (*object_category == OBJ_CYLINDER)
		validate_cylinder(object);
	else if (*object_category == OBJ_CYLINDER_BASE)
		validate_cylinder_base(object);
	else
		panic("failed to validate object: unexpected object");
}
