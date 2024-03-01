#include "object.h"

unsigned int	get_plane_color(const t_plane *plane)
{
	unsigned int	color;

	color = 0;
	color = (char)plane->color.x;
	color = color << 8;
	color = (char)plane->color.y;
	color = color << 8;
	color = (char)plane->color.z;
	return (color);
}
