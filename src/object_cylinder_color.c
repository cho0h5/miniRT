#include "object.h"

unsigned int	get_cylinder_color(const t_cylinder *cylinder)
{
	unsigned int	color;

	color = 0;
	color = (unsigned char)cylinder->color.x;
	color = color << 8;
	color = (unsigned char)cylinder->color.y;
	color = color << 8;
	color = (unsigned char)cylinder->color.z;
	return (color);
}
