#include <stdio.h>
#include "object.h"

void	sphere_print(const t_sphere *sphere)
{
	printf("sphere\n");
	printf("- position: ");
	vec3_print(sphere->position);
	printf("\n");
	printf("- diameter: %f\n", sphere->diameter);
	printf("- color: ");
	vec3_print(sphere->color);
	printf("\n");
}
