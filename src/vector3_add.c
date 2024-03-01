#include "vector3.h"

t_vector3	add(const t_vector3 vec1, const t_vector3 vec2)
{
	t_vector3	result;

	result.x = vec1.x + vec2.x;
	result.y = vec1.y + vec2.y;
	result.z = vec1.z + vec2.z;
	return (result);
}
