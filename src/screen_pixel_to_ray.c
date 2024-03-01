#include <math.h>
#include "screen.h"
#include "vector3.h"

static t_vector3	get_normalized_ray(double fov, int i, int j)
{
	const double	dx = tan((fov / 2) * (M_PI / 180)) / ((double)WIDTH / 2);
	t_vector3		ray;

	ray.x = (i - (double)WIDTH / 2) * dx;
	ray.y = 1;
	ray.z = ((double)WIDTH / 2 - j) * dx;
	return (ray);
}

t_vector3	pixel_to_ray(const t_camera *camera, int i, int j)
{
	const t_vector3 normalized_ray = get_normalized_ray(camera->fov, i, j);
	return (normalized_ray);
}
