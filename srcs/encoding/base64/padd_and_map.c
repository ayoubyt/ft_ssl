#include "ft_base64.h"

static char *base64map(byte_t *dst, byte_t *src, size_t size)
{
	char *result = NULL;
	byte_t cursor = 2;
	byte_t reserve = 0;
	byte_t index, index2;

	result = ft_memalloc(((size * sizeof(char) * 4) / 3) + 1);
	int j = 0;
	for (size_t i = 0; i < size; i++)
	{
		byte_t b = src[i];
		switch (i % 3)
		{
		case 0:
			index = b >> 2;
			reserve = b & 0b00000011;
			result[j++] = BASE64_CHARS[index];
			break;
		case 1:
			index = (b >> 4) | (reserve << 4);
			reserve = b & 0b00001111;
			result[j++] = BASE64_CHARS[index];
			break;
		case 2:
			index = (b >> 6) | (reserve << 2);
			result[j++] = BASE64_CHARS[index];
			index = b & 0b00111111;
			result[j++] = BASE64_CHARS[index];
			break;
		}
	}
	return result;
}

char *padd_and_map(byte_t *data, size_t size)
{
	char *padded_data = NULL;
	char *result = NULL;
	size_t padded_size = size;
	int added_pad_size = (3 - (size % 3));

	if (added_pad_size != 3)
		padded_size += added_pad_size;
	else
		added_pad_size = 0;

	padded_data = ft_memalloc(padded_size * sizeof(char));
	result = base64map(padded_data, data, padded_size);

	for (size_t i = 0; i < added_pad_size; i++)
		padded_data[size - 1 - i] = BASE64_PAD;
	return result;
}
