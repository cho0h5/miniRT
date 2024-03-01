#include "vector3.h"

t_vector3	scale(const t_vector3 vec, double a)
{
	t_vector3	result;

	result.x = vec.x * a;
	result.y = vec.y * a;
	result.z = vec.z * a;
	return (result);
}
