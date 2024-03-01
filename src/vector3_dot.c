#include "vector3.h"

double	dot(const t_vector3 vec1, const t_vector3 vec2)
{
	double	dot_product;

	dot_product = 0;
	dot_product += vec1.x * vec2.x;
	dot_product += vec1.y * vec2.y;
	dot_product += vec1.z * vec2.z;
	return (dot_product);
}
