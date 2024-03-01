#include <math.h>
#include "vector3.h"
#include "object.h"

t_rotate_info	init_rotate_info(const t_camera *camera)
{
	const double	theta = angle(camera->orientation, vector3(0, 1, 0));
	t_rotate_info	info;

	info.axis_term = cross(camera->orientation, vector3(0, 1, 0));
	info.sin_term = sin(theta);
	info.cos_term= cos(theta);
	return (info);
}

t_vector3	rotate(const t_rotate_info *info, const t_vector3 vec)
{
	t_vector3	tmp1;
	t_vector3	tmp2;

	tmp1 = scale(vec, info->cos_term);
	tmp2 = scale(cross(info->axis_term, vec), info->sin_term);
	return (add(tmp1, tmp2));
}
