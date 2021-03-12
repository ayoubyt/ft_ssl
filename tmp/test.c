#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

#define REV32(x) (             \
	(((x)&0x000000FF) << 24) | \
	(((x)&0x0000FF00) << 8) |  \
	(((x)&0xFF000000) >> 24) | \
	(((x)&0x00FF0000) >> 8))

int main()
{
	char *ss[] = {[1] = "zb", [0] = "tarma"};

	printf("0 = %s\n1 = %s\n", ss[0], ss[1]);
}
