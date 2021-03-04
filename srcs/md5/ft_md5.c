/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguert <aaguert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 23:32:16 by ayoubyt           #+#    #+#             */
/*   Updated: 2021/03/04 12:46:06 by aaguert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

void print_mem(unsigned char *data, int size)
{
	printf("size = %d\n", size);
	for (size_t i = 0; i < size; i++)
	{
		printf("%x ", data[i]);
	}
	printf("\n");
}

void		ft_get_padded_data(
								unsigned char *data,
								size_t len,
								unsigned char **result_data,
								size_t *result_len
)
{
	int				new_len;
	unsigned char	*padded_data;
	int				added_len;
	uint64_t		original_length_int_bits;

	if (len % 64 < 56)
		added_len = (56 - (len % 64));
	else
		added_len = 64 - (len % 64 - 56);
	added_len += 8;
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

void		md5_ctx_init(t_md5_ctx *ctx, unsigned char *data, size_t len)
{
	ft_get_padded_data(data, len, &ctx->buff, &ctx->buff_size);
	ctx->a = A0;
	ctx->b = B0;
	ctx->c = C0;
	ctx->d = D0;
}

void		ft_print_md5_digest(uint32_t *digest)
{
	int				i;
	unsigned char	*digest_bytes;

	digest_bytes = (unsigned char*)digest;
	printf("0x");
	i = 0;
	while (i < 16)
	{
		printf("%x", digest_bytes[i]);
		i++;
	}
	printf("\n");
}

uint32_t	*ft_md5(unsigned char *data, size_t len)
{
	static uint32_t	digest[4];
	t_md5_ctx		md5_ctx;

	md5_ctx_init(&md5_ctx, data, len);
	ft_md5_process(&md5_ctx, digest);
	free(md5_ctx.buff);
	return (digest);
}
