#include <fcntl.h>
#include "parse.h"
#include "environment.h"
#include "get_next_line.h"
#include "panic.h"

void	parse(t_environment *env, const char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		panic("failed to open");
	line = get_next_line(fd);
	while (line != NULL)
	{
		parse_line(env, line);
		free(line);
		line = get_next_line(fd);
	}
}
