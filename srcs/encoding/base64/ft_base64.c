#include "ft_base64.h"

char *ft_base64_encode(byte_t *data, size_t size)
{
	return padd_and_map(data, size);
}

void print_base64(byte_t *base64data, size_t size)
{
	for (size_t i = 0; i < size; i++)
		ft_putchar(base64data[i]);
	ft_putchar('\n');
}
