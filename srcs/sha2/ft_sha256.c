/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoubyt <ayoubyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 16:37:22 by aaguert           #+#    #+#             */
/*   Updated: 2021/03/09 13:13:47 by ayoubyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha2.h"

const word_t K[64] = {
	0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
	0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
	0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
	0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
	0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
	0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
	0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
	0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2};

void get_padded_data(byte_t *data, size_t size, byte_t **padded_data, size_t *new_size)
{
	// size of input data in bits
	unsigned bit_len;
	// length added to 'size' to satisfy: size + added_size ≡ 0 [64];
	unsigned added_size;
	// lenth of padded data

	bit_len = size * 8;
	added_size = 64 - (size + 1 + 8) % 64;
	*new_size = size + added_size;
	*padded_data = malloc(*new_size);
	ft_memcpy(*padded_data, data, size);
	// adding on bit, 0x80 = 0b10000000
	*padded_data[size] = 0x80;
	// padding with remaining memory eith zeros
	ft_bzero(*padded_data + size + 1, added_size - 1);
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

word_t *sha256(byte_t *data, size_t size)
{
}