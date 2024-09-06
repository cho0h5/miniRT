#include "validate.h"

void	validate_light(const t_light *light)
{
	validate_range(0, 1, light->brightness);
	validate_color(light->color);
}
