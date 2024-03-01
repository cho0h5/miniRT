#include "vector3.h"

t_vector3	cross(const t_vector3 vec1, const t_vector3 vec2)
{
	t_vector3	cross_product;

	cross_product.x = (vec1.y * vec2.z) - (vec1.z * vec2.y);
	cross_product.y = (vec1.z * vec2.x) - (vec1.x * vec2.z);
	cross_product.z = (vec1.x * vec2.y) - (vec1.y * vec2.x);
	return (cross_product);
}
