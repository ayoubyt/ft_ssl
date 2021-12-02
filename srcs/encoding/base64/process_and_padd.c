#include "ft_base64.h"

byte_t *process_and_padd(byte_t *data, size_t size) {
	char *padded_data = NULL;
	int padded_size = size;

	if (size % 3)
		padded_size += (3 - (size % 3));
	padded_data = malloc(padded_size * sizeof(char));
	return padded_data;
}
