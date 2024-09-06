#include "parse.h"
#include "validate.h"

void	normalize_orientation(t_vector3 *orientation)
{
	const double	mag = magnitude(*orientation);

	validate_range(0.1, 10, mag);
	orientation->x /= mag;
	orientation->y /= mag;
	orientation->z /= mag;
}
