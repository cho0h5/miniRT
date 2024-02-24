#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

#include "libft.h"

typedef struct s_environment
{
	t_list	*lights;
	t_list	*cameras;
	t_list	*ambients;
	t_list	*objects;
}	t_environment;

void	init_environment(t_environment *env);

#endif
