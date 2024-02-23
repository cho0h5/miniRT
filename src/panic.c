#include <stdio.h>
#include <stdlib.h>
#include "panic.h"

void	panic(char *error_message)
{
	printf("error: %s\n", error_message);
	exit(1);
}
