#include <mlx.h>
#include "screen.h"

static void	put_mlx_pixel(t_mlx_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->address + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw(t_environment *env)
{
	t_rotate_info	info = init_rotate_info(env->cameras->content);

	for (int j = 0; j < WIDTH; j++) {
		for (int i = 0; i < WIDTH; i++) {
			t_vector3 ray = pixel_to_ray(env->cameras->content, &info, i, j);
			(void)ray;
			put_mlx_pixel(&env->image, i, j, 0xffffff);
		}
	}
	mlx_put_image_to_window(env->mlx, env->mlx_window, env->image.image, 0, 0);
}
