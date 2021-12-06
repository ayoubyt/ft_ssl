#include "ft_base64.h"

char *ft_base64_encode(byte_t *data, size_t size)
{
	return padd_and_map(data, size);
}

void print_base64(char *base64)
{
	int i = 0;
	while (base64[i])
	{
		if (i % 76 == 0 && i > 0)
			ft_putchar('\n');
		ft_putchar(base64[i]);
		i++;
	}
	ft_putchar('\n');
}
