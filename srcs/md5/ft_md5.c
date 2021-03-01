/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoubyt <ayoubyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 23:32:16 by ayoubyt           #+#    #+#             */
/*   Updated: 2021/03/02 00:47:49 by ayoubyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

char		*ft_get_padded_data(
							char *data,
							size_t len,
							char **result_data,
							size_t *result_len
)
{
	int			new_len;
	char		*padded_data;
	int			added_len;
	uint64_t	original_length_int_bits;

	added_len = (len % 64 ? (64 - len % 64) : 64);
	new_len = len + added_len;
	padded_data = malloc(new_len);
	ft_memcpy(padded_data, data, len);
	padded_data[len] = 0x80;
	ft_bzero(padded_data + len + 1, added_len - 1);
	original_length_int_bits = (len * 8);
	ft_memcpy(padded_data + (new_len - 8), &original_length_int_bits, 8);
	*result_data = padded_data;
	*result_len = new_len;
}

uint32_t	ft_md5(char *data, size_t len)
{
	size_t		new_len;
	char		*padded_data;

	ft_get_padded_data(data, len, &padded_data, &new_len);
}
