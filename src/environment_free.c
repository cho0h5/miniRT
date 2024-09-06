#include <mlx.h>
#include "libft.h"
#include "environment.h"

void	free_environment(t_environment *env)
{
	ft_lstclear(&env->lights, free);
	ft_lstclear(&env->cameras, free);
	ft_lstclear(&env->ambients, free);
	ft_lstclear(&env->objects, free);
	mlx_destroy_image(env->mlx, env->image.image);
	mlx_destroy_window(env->mlx, env->mlx_window);
	free(env->mlx);
}
