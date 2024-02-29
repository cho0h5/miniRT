#include <stdio.h>
#include "vector3.h"

void	vec3_print(const t_vector3 vec)
{
	printf("(%.2f, %.2f, %.2f)", vec.x, vec.y, vec.z);
}
