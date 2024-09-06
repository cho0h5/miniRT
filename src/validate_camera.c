#include "validate.h"

void	validate_camera(const t_camera *camera)
{
	validate_orientation(&camera->orientation);
	validate_range(1, 180, camera->fov);
}
