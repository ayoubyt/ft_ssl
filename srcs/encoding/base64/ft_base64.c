#include "ft_base64.h"

data_t ft_base64_encode(byte_t *data, size_t size)
{
	return padd_and_map(data, size);
}

data_t ft_base64_decode(byte_t *data, size_t size)
{
	data_t cleaned_data;
	data_t result;

	init_base64map_list();
	cleaned_data = base64_clean_and_check(data, size);
	result = base64_reverse_map(cleaned_data.content, cleaned_data.size);

	return result;
}

void print_base64(data_t data, int fd)
{
	if (fd > 0)
	{
		int i = 0;
		while (i < data.size)
		{
			if (i % 64 == 0 && i > 0)
				ft_putchar_fd('\n', fd);
			ft_putchar_fd(data.content[i], fd);
			i++;
		}
		ft_putchar_fd('\n', fd);
	}
}

void print_data(data_t result, int fd)
{
	for (size_t i = 0; i < result.size; i++)
		ft_putchar_fd(result.content[i], fd);
}
