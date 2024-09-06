#include "validate.h"

void	validate_ambient(const t_ambient *ambient)
{
	validate_range(0, 1, ambient->ratio);
	validate_color(ambient->color);
}
