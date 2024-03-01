#ifndef SCREEN_H
# define SCREEN_H

# include "environment.h"
# include "vector3.h"
# include "object.h"

# define WIDTH 720
# define ON_DESTROY 17

t_vector3	pixel_to_ray(const t_camera *camera, const t_rotate_info *info, int i, int j);
void		draw(t_environment *env);
int			destroy_screen(t_environment *env);
int			key_hook(int keycode, t_environment *env);

#endif
