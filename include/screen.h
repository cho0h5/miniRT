#ifndef SCREEN_H
# define SCREEN_H

# include "vector3.h"
# include "object.h"

# define WIDTH 6

t_vector3	pixel_to_ray(const t_camera *camera, int i, int j);

#endif
