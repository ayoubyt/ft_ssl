#include "ft_base64.h"

static char *base64map(byte_t *data, size_t size)
{
	char *result = NULL;
	byte_t cursor = 2;
	byte_t reserve = 0;
	byte_t index, index2;

	result = ft_memalloc(((size * sizeof(char) * 4) / 3) + 1);
	int j = 0;
	for (size_t i = 0; i < size; i++)
	{
		byte_t b = data[i];
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

	// if *size* is not a multiple of 3, padd it to be
	if (added_pad_size != 3)
		padded_size += added_pad_size;
	else
		added_pad_size = 0;

	// alocating the padded (or not) memory
	padded_data = ft_memalloc(padded_size * sizeof(char));
	ft_memcpy(padded_data, data, size);
	// mapping each 6 bits in
	result = base64map(padded_data, padded_size);
	free(padded_data);
	for (size_t i = 0; i < added_pad_size; i++)
		result[((padded_size * 4) / 3) - 1 - i] = BASE64_PAD;
	return result;
}

static base64_input_error()
{
	ft_putendl_fd("error : invalid input", 2);
	exit(EXIT_FAILURE);
}

static void init_base64map_list(int base64map_list[255])
{
	for (size_t i = 0; i < 255; i++)
		base64map_list[i] = -1;

	base64map_list['A'] = 0;
	base64map_list['B'] = 1;
	base64map_list['C'] = 2;
	base64map_list['D'] = 3;
	base64map_list['E'] = 4;
	base64map_list['F'] = 5;
	base64map_list['G'] = 6;
	base64map_list['H'] = 7;
	base64map_list['I'] = 8;
	base64map_list['J'] = 9;
	base64map_list['K'] = 10;
	base64map_list['L'] = 11;
	base64map_list['M'] = 12;
	base64map_list['N'] = 13;
	base64map_list['O'] = 14;
	base64map_list['P'] = 15;
	base64map_list['Q'] = 16;
	base64map_list['R'] = 17;
	base64map_list['S'] = 18;
	base64map_list['T'] = 19;
	base64map_list['U'] = 20;
	base64map_list['V'] = 21;
	base64map_list['W'] = 22;
	base64map_list['X'] = 23;
	base64map_list['Y'] = 24;
	base64map_list['Z'] = 25;
	base64map_list['a'] = 26;
	base64map_list['b'] = 27;
	base64map_list['c'] = 28;
	base64map_list['d'] = 29;
	base64map_list['e'] = 30;
	base64map_list['f'] = 31;
	base64map_list['g'] = 32;
	base64map_list['h'] = 33;
	base64map_list['i'] = 34;
	base64map_list['j'] = 35;
	base64map_list['k'] = 36;
	base64map_list['l'] = 37;
	base64map_list['m'] = 38;
	base64map_list['n'] = 39;
	base64map_list['o'] = 40;
	base64map_list['p'] = 41;
	base64map_list['q'] = 42;
	base64map_list['r'] = 43;
	base64map_list['s'] = 44;
	base64map_list['t'] = 45;
	base64map_list['u'] = 46;
	base64map_list['v'] = 47;
	base64map_list['w'] = 48;
	base64map_list['x'] = 49;
	base64map_list['y'] = 50;
	base64map_list['z'] = 51;
	base64map_list['0'] = 52;
	base64map_list['1'] = 53;
	base64map_list['2'] = 54;
	base64map_list['3'] = 55;
	base64map_list['4'] = 56;
	base64map_list['5'] = 57;
	base64map_list['6'] = 58;
	base64map_list['7'] = 59;
	base64map_list['8'] = 60;
	base64map_list['9'] = 61;
	base64map_list['+'] = 62;
	base64map_list['/'] = 63;
}

data_t base64_decode(byte_t *data, size_t size)
{
	int base64map_list[255];
	int padding = 0;
	byte_t prev_bits = 0;
	byte_t cur_bits;
	data_t result = {0, 0};

	init_base64map_list(base64map_list);

	if (size % 4 != 0 || (size < 4 && size > 0))
		base64_input_error();

	int i = 0;
	while (i < 3)
	{
		if (i >= 2)
			base64_input_error();
		if (data[size - 1 - 1] == '=')
			padding++;
		i++;
	}

	result.content = ft_memalloc((((size * 4) / 3) - padding));
	result.size = ((((size * 4) / 3) - padding));

	for (size_t i = 0; i < size; i++)
	{
		uint8_t unit = base64map_list[data[i]];

		if (unit == -1)
			base64_input_error();

		switch (i % 4)
		{
		case 0:
			result.content[i] |= unit << 2;
			break;
		case 1:
			result.content[i - 1] |= unit >> 4;
			result.content[i] |= unit << 4;
			break;
		case 2:
			result.content[i - 1] |= unit >> 4;
			result.content[i] |= unit << 6;
			break;
		case 3:
			result.content[i - 1] |= unit;
			break;
		}
	}

	return result;
}

data_t base64_clean(byte_t data, size_t size)
{
	data_t result = {0, 0};

	for (size_t i = 0; i < size; i++)
	{
		// if (f)
	}

}
