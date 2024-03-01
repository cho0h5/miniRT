#include "object.h"
#include "vector3.h"

t_object_category	*get_closest_object(const t_vector3 pos, const t_vector3 ray, t_list *objects)
{
	t_list				*node;
	double				distance;
	double				closest_distance;
	t_object_category	*closest_object;

	node = objects;
	closest_distance = DOUBLE_MAX;
	closest_object = NULL;
	while (node)
	{
		distance = object_distance(pos, ray, node->content);
		if (distance < closest_distance) {
			closest_distance = distance;
			closest_object = node->content;
		}
		node = node->next;
	}
	return (closest_object);
}
