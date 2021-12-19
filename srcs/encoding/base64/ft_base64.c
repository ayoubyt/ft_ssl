#include "ft_base64.h"

char *ft_base64_encode(byte_t *data, size_t size)
{
	return padd_and_map(data, size);
}

void print_base64(char *base64, int fd)
{
	if (fd > 0)
	{
		int i = 0;
		while (base64[i])
		{
			if (i % 64 == 0 && i > 0)
				ft_putchar_fd('\n', fd);
			ft_putchar_fd(base64[i], fd);
			i++;
		}
		ft_putchar_fd('\n', fd);
	}
}
