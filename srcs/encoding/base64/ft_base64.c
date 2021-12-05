#include "ft_base64.h"

char *ft_base64_encode(byte_t *data, size_t size)
{
	return padd_and_map(data, size);
}
