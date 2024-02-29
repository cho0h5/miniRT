#include <stdio.h>
#include "object.h"
#include "vector3.h"

void	light_print(const t_light *light)
{
	printf("light\n");
	printf("- position: ");
	vec3_print(light->position);
	printf("\n");
	printf("- brightness: %f\n", light->brightness);
	printf("- color: ");
	vec3_print(light->color);
	printf("\n");
}
