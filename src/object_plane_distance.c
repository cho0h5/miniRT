#include "object.h"
#include "vector3.h"

double	plane_distance(const t_vector3 pos, const t_vector3 ray, const t_plane *plane)
{
	const t_vector3	pc_vec = subtract(plane->position, pos);
	const double	numerator = dot(pc_vec, plane->normal);
	const double	denominator = dot(ray, plane->normal);
	const double	distance = numerator / denominator;

	if (distance < 0)
		return (DOUBLE_MAX);
	return (distance);
}
