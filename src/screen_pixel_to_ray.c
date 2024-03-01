#include <math.h>
#include "screen.h"
#include "vector3.h"

static t_vector3	get_normalized_ray(const t_camera *camera, int i, int j)
{
	const double	dx = tan((camera->fov / 2) * (M_PI / 180)) / ((double)WIDTH / 2);
	t_vector3		ray;

	ray.x = (i - (double)WIDTH / 2) * dx;
	ray.y = 1;
	ray.z = ((double)WIDTH / 2 - j) * dx;
	return (ray);
}

t_vector3	pixel_to_ray(const t_camera *camera, int i, int j)
{
	return (get_normalized_ray(camera, i, j));
}
