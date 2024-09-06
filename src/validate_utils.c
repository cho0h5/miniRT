#include "validate.h"
#include "panic.h"

void	validate_range(const double mininum, const double maximum, const double x)
{
	if (mininum > x)
		panic("validation fail (range)");
	if (maximum < x)
		panic("validation fail (range)");
}

void	validate_positive(const double x)
{
	if (x < 0)
		panic("validation fail (positive)");
}

void	validate_orientation(t_vector3 *orientation)
{
	const double	mag = magnitude(*orientation);
	validate_range(0.1, 10, mag);
	orientation->x /= mag;
	orientation->y /= mag;
	orientation->z /= mag;
}

void	validate_color(const t_vector3 color)
{
	validate_range(0, 255, color.x);
	validate_range(0, 255, color.y);
	validate_range(0, 255, color.z);
}
