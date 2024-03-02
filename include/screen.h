#ifndef SCREEN_H
# define SCREEN_H

# include "environment.h"
# include "vector3.h"
# include "object.h"

# define WIDTH 720
# define ON_DESTROY 17

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_UP 123
# define KEY_DOWN 124
# define KEY_LEFT 125
# define KEY_RIGHT 126

t_vector3	pixel_to_ray(const t_camera *camera, const t_rotate_info *info, int i, int j);
void		draw(t_environment *env);
int			destroy_screen(t_environment *env);
int			key_hook(int keycode, t_environment *env);

#endif
