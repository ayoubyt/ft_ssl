/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguert <aaguert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 16:37:22 by aaguert           #+#    #+#             */
/*   Updated: 2021/03/10 17:51:35 by aaguert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha2.h"

void get_padded_data(byte_t *data, size_t size, byte_t **padded_data, size_t *new_size)
{
	// size of input data in bits
	unsigned bit_len;
	// length added to 'size' to satisfy: size + added_size ≡ 0 [64];
	unsigned added_size;
	// lenth of padded data

	bit_len = size * 8;
	added_size = 64 - ((size + 1 + 8) % 64);
	*new_size = size + added_size;
	*padded_data = malloc(*new_size);
	ft_memcpy(*padded_data, data, size);
	// adding on bit, 0x80 = 0b10000000
	*padded_data[size] = 0x80;
	// padding  remaining memory with zeros
	ft_bzero(*padded_data + size + 1, added_size - 1);
	// converting 'bit_len' to big endian
	bit_len = REV32(bit_len);
	ft_memcpy(*padded_data + (*new_size - 8), &bit_len, 8);
}

void init_ctx(sha256_ctx_t *ctx, byte_t *data, size_t size)
{
	ctx->h0 = 0x6a09e667;
	ctx->h1 = 0xbb67ae85;
	ctx->h2 = 0x3c6ef372;
	ctx->h3 = 0xa54ff53a;
	ctx->h4 = 0x510e527f;
	ctx->h5 = 0x9b05688c;
	ctx->h6 = 0x1f83d9ab;
	ctx->h7 = 0x5be0cd19;
	get_padded_data(data, size, &ctx->buff, &ctx->buffsize);
}

void ft_sha256_finalize(sha256_ctx_t *ctx, byte_t *digest)
{
	word_t *wdigest = (word_t*)(digest);

	ctx->h0 = REV32(ctx->h0);
	ctx->h1 = REV32(ctx->h1);
	ctx->h2 = REV32(ctx->h2);
	ctx->h3 = REV32(ctx->h3);
	ctx->h4 = REV32(ctx->h4);
	ctx->h5 = REV32(ctx->h5);
	ctx->h6 = REV32(ctx->h6);
	ctx->h7 = REV32(ctx->h7);
	ft_memcpy(wdigest + 0, ctx->h0, 4);
	ft_memcpy(wdigest + 1, ctx->h1, 4);
	ft_memcpy(wdigest + 2, ctx->h2, 4);
	ft_memcpy(wdigest + 3, ctx->h3, 4);
	ft_memcpy(wdigest + 4, ctx->h4, 4);
	ft_memcpy(wdigest + 5, ctx->h5, 4);
	ft_memcpy(wdigest + 6, ctx->h6, 4);
	ft_memcpy(wdigest + 7, ctx->h7, 4);
}


byte_t *sha256(byte_t *data, size_t size)
{
	static byte_t	digest[32];
	sha256_ctx_t	ctx;

	init_ctx(&ctx, data, size);
	ft_sha256_process(&ctx, digest);
	ft_sha256_finalize(&ctx, digest);
}
