#include "md5.h"

/*
** message must padded to satisfy the folowing conditions
** 
*/

char*		ft_get_padded_data(char* data,
								size_t len,
								char* padded_data,
								size_t* new_len)
{
	int			new_len;
	char*		padded_data;
	int			padded_len;
	uint64_t	original_length_int_bits;

	padded_len = (len % 64 ? 64 : (64 - len % 64));
	new_len = len + padded_len;
	ft_memcpy(padded_data, data, len);
	padded_data[len] = 1;
	ft_bzero(padded_data + len + 1, padded_len - 1);
	original_length_int_bits = (len * 8);
	ft_memcpy(data + (new_len - 8), &original_length_int_bits, 8);
}

uint32_t ft_md5(char *data, size_t len)
{
	int		new_len;
	char*	padded_data;


}