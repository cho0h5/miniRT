#include <libft.h>
#include <get_next_line.h>
#include <stdio.h>

int	main()
{
	for (int i = 0; i < 5; i++) {
		char **strs = ft_split(get_next_line(0), ' ');
		for (; *strs != NULL; strs++) {
			printf("%s\n", *strs);
		}
	}
}
