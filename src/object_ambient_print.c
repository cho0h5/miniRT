#include <stdio.h>
#include "object.h"

void	ambient_print(const t_ambient *ambient)
{
	printf("ambient\n");
	printf("- ratio: %.2f\n", ambient->ratio);
	printf("- color: ");
	vec3_print(ambient->color);
	printf("\n");
}
