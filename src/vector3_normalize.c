#include "vector3.h"

t_vector3	normalize(const t_vector3 vec)
{
	const double	mag = magnitude(vec);
	t_vector3		normalized;

	normalized.x = vec.x / mag;
	normalized.y = vec.y / mag;
	normalized.z = vec.z / mag;
	return (normalized);
}
