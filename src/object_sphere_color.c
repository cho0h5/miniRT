#include "object.h"

unsigned int	get_sphere_color(const t_sphere *sphere)
{
	unsigned int	color;

	color = 0;
	color = (unsigned char)sphere->color.x;
	color = color << 8;
	color = (unsigned char)sphere->color.y;
	color = color << 8;
	color = (unsigned char)sphere->color.z;
	return (color);
}
