#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

int main()
{
	char s[] = "abcd";
	uint32_t u = 0x6162;
	unsigned char c = u;

	for (size_t i = 0; i < 4; i++)
		printf("%02x:", *(((char*)&u) + i));
	printf("\n");
	
	printf("%c\n", c);
}