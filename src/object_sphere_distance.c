#include "object.h"
#include "vector3.h"

double	sphere_distance(const t_vector3 pos, const t_vector3 ray, const t_sphere *sphere)
{
	const double	radius = sphere->diameter / 2;
	t_vector3	ps_vec;
	double		b;
	double		c;
	double		discriminant;

	ps_vec = subtract(pos, sphere->position);
	b = 2 * dot(ps_vec, ray);
	c = magnitude(ps_vec) - radius * radius;
	discriminant = b * b - 4 * c;
	if (discriminant >= 0)
		return (1);

	return (DOUBLE_MAX);
}
