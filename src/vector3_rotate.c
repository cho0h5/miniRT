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

#include <stdio.h>
t_vector3	rotate(const t_rotate_info *info, const t_vector3 vec)
{
	t_vector3	tmp1;
	t_vector3	tmp2;

	printf("\n");
	printf("normalized vec: ");
	vec3_print(vec);
	printf("\n");
	tmp1 = scale(vec, info->cos_term);
	tmp2 = scale(cross(info->axis_term, vec), info->sin_term);
	printf("tmp2: ");
	vec3_print(tmp2);
	printf("\n");
	return (add(tmp1, tmp2));
}
