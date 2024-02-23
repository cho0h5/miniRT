#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

#include "libft.h"

typedef struct s_environment
{
	t_list	*lights;
	t_list	*camera;
	t_list	*ambient;
	t_list	*objects;
}	t_environment;

#endif
