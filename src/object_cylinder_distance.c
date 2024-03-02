#include <math.h>
#include "object.h"
#include "vector3.h"

double	cylinder_distance(const t_vector3 pos, const t_vector3 ray, const t_cylinder *cylinder)
{
	const t_vector3	normal_vec = normalize(cross(ray, cylinder->axis));
	const double	distance = dot(subtract(pos, cylinder->position), normal_vec);

	if (fabs(distance) <= cylinder->diameter / 2)
		return (distance);
	return (DOUBLE_MAX);
}
