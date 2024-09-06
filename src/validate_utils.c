#include "validate.h"
#include "panic.h"
#include <stdio.h>

void	validate_range(const double mininum, const double maximum, const double x)
{
	if (mininum > x) {
		panic("validation fail (range)");
		printf("x: %f\n", x);
	}
	if (maximum < x) {
		panic("validation fail (range)");
		printf("x: %f\n", x);
	}
}

void	validate_positive(const double x)
{
	if (x < 0) {
		panic("validation fail (positive)");
		printf("x: %f\n", x);
	}
}

void	validate_orientation(const t_vector3 *orientation)
{
	const double	mag = magnitude(*orientation);
	validate_range(0.9, 1.1, mag);
}

void	validate_color(const t_vector3 color)
{
	validate_range(0, 255, color.x);
	validate_range(0, 255, color.y);
	validate_range(0, 255, color.z);
}
