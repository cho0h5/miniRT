#include <stdio.h>
#include "object.h"
#include "vector3.h"

void	camera_print(const t_camera *camera)
{
	printf("camera\n");
	printf("- position: ");
	vec3_print(camera->position);
	printf("\n");
	printf("- orientation: ");
	vec3_print(camera->orientation);
	printf("\n");
	printf("- fov: %f\n", camera->fov);
}
