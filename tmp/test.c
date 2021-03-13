#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

#include "libft.h"

int main()
{
	// int fd = open("t.py", O_RDONLY);
	char *s = ft_readall(0);

	printf("|%s|\n", s);
	free(s);
}
