#include <math.h>
#include "vector3.h"
#include "object.h"

t_rotate_info	init_rotate_info(const t_camera *camera)
{
	const double	theta = acos(angle(camera->orientation, vector3(0, 1, 0)));
	t_rotate_info	info;

	info.axis_term = cross(vector3(0, 1, 0), camera->orientation);
	info.sin_term = sin(theta);
	info.cos_term = cos(theta);
	return (info);
}

t_vector3	rotate(const t_rotate_info *info, const t_vector3 vec)
{
	t_vector3	tmp1;
	t_vector3	tmp2;
	t_vector3	tmp3;
	t_vector3	tmp4;

	tmp1 = scale(info->axis_term, dot(info->axis_term, vec) * (1 - info->cos_term));
	tmp2 = scale(vec, info->cos_term);
	tmp3 = scale(cross(info->axis_term, vec), info->sin_term);
	tmp4 = add(tmp1, add(tmp2, tmp3));
	return (normalize(tmp4));
}

t_vector3	rotate2(const t_vector3 axis, double theta, const t_vector3 vec)
{
	const double	sin_term = sin(theta);
	const double	cos_term = cos(theta);
	t_vector3		tmp1;
	t_vector3		tmp2;
	t_vector3		tmp3;

	tmp1 = scale(axis, (1 - cos_term) * dot(axis, vec));
	tmp2 = scale(vec, cos_term);
	tmp3 = scale(cross(axis, vec), sin_term);
	return (add(tmp1, add(tmp2, tmp3)));
}
