#ifndef SCREEN_H
# define SCREEN_H

# include "vector3.h"
# include "object.h"

# define WIDTH 4

t_vector3	pixel_to_ray(const t_camera *camera, const t_rotate_info *info, int i, int j);

#endif
