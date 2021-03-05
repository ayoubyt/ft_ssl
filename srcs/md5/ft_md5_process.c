/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguert <aaguert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 12:09:06 by ayoubyt           #+#    #+#             */
/*   Updated: 2021/03/04 12:37:18 by aaguert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

const uint32_t g_t[64] =
{
	0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
	0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
	0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
	0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
	0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
	0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
	0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
	0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
	0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
	0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
	0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
	0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
	0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
	0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
	0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
	0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
};


void	round1(t_md5_ctx *c, size_t idx)
{
	uint32_t *ibuff;

	ibuff = (uint32_t*)c->buff;
	R1O(c->a, c->b, c->c, c->d, ibuff[idx * 16 + 0], 7, g_t[0]);
	R1O(c->d, c->a, c->b, c->c, ibuff[idx * 16 + 1], 12, g_t[1]);
	R1O(c->c, c->d, c->a, c->b, ibuff[idx * 16 + 2], 17, g_t[2]);
	R1O(c->b, c->c, c->d, c->a, ibuff[idx * 16 + 3], 22, g_t[3]);
	R1O(c->a, c->b, c->c, c->d, ibuff[idx * 16 + 4], 7, g_t[4]);
	R1O(c->d, c->a, c->b, c->c, ibuff[idx * 16 + 5], 12, g_t[5]);
	R1O(c->c, c->d, c->a, c->b, ibuff[idx * 16 + 6], 17, g_t[6]);
	R1O(c->b, c->c, c->d, c->a, ibuff[idx * 16 + 7], 22, g_t[7]);
	R1O(c->a, c->b, c->c, c->d, ibuff[idx * 16 + 8], 7, g_t[8]);
	R1O(c->d, c->a, c->b, c->c, ibuff[idx * 16 + 9], 12, g_t[9]);
	R1O(c->c, c->d, c->a, c->b, ibuff[idx * 16 + 10], 17, g_t[10]);
	R1O(c->b, c->c, c->d, c->a, ibuff[idx * 16 + 11], 22, g_t[11]);
	R1O(c->a, c->b, c->c, c->d, ibuff[idx * 16 + 12], 7, g_t[12]);
	R1O(c->d, c->a, c->b, c->c, ibuff[idx * 16 + 13], 12, g_t[13]);
	R1O(c->c, c->d, c->a, c->b, ibuff[idx * 16 + 14], 17, g_t[14]);
	R1O(c->b, c->c, c->d, c->a, ibuff[idx * 16 + 15], 22, g_t[15]);
}

void	round2(t_md5_ctx *c, size_t idx)
{
	uint32_t *ibuff;

	ibuff = (uint32_t*)c->buff;
	R2O(c->a, c->b, c->c, c->d, ibuff[idx * 16 + 1], 5, g_t[16]);
	R2O(c->d, c->a, c->b, c->c, ibuff[idx * 16 + 6], 9, g_t[17]);
	R2O(c->c, c->d, c->a, c->b, ibuff[idx * 16 + 11], 14, g_t[18]);
	R2O(c->b, c->c, c->d, c->a, ibuff[idx * 16 + 0], 20, g_t[19]);
	R2O(c->a, c->b, c->c, c->d, ibuff[idx * 16 + 5], 5, g_t[20]);
	R2O(c->d, c->a, c->b, c->c, ibuff[idx * 16 + 10], 9, g_t[21]);
	R2O(c->c, c->d, c->a, c->b, ibuff[idx * 16 + 15], 14, g_t[22]);
	R2O(c->b, c->c, c->d, c->a, ibuff[idx * 16 + 4], 20, g_t[23]);
	R2O(c->a, c->b, c->c, c->d, ibuff[idx * 16 + 9], 5, g_t[24]);
	R2O(c->d, c->a, c->b, c->c, ibuff[idx * 16 + 14], 9, g_t[25]);
	R2O(c->c, c->d, c->a, c->b, ibuff[idx * 16 + 3], 14, g_t[26]);
	R2O(c->b, c->c, c->d, c->a, ibuff[idx * 16 + 8], 20, g_t[27]);
	R2O(c->a, c->b, c->c, c->d, ibuff[idx * 16 + 13], 5, g_t[28]);
	R2O(c->d, c->a, c->b, c->c, ibuff[idx * 16 + 2], 9, g_t[29]);
	R2O(c->c, c->d, c->a, c->b, ibuff[idx * 16 + 7], 14, g_t[30]);
	R2O(c->b, c->c, c->d, c->a, ibuff[idx * 16 + 12], 20, g_t[31]);
}

void	round3(t_md5_ctx *c, size_t idx)
{
	uint32_t *ibuff;

	ibuff = (uint32_t*)c->buff;
	R3O(c->a, c->b, c->c, c->d, ibuff[idx * 16 + 5], 4, g_t[32]);
	R3O(c->d, c->a, c->b, c->c, ibuff[idx * 16 + 8], 11, g_t[33]);
	R3O(c->c, c->d, c->a, c->b, ibuff[idx * 16 + 11], 16, g_t[34]);
	R3O(c->b, c->c, c->d, c->a, ibuff[idx * 16 + 14], 23, g_t[35]);
	R3O(c->a, c->b, c->c, c->d, ibuff[idx * 16 + 1], 4, g_t[36]);
	R3O(c->d, c->a, c->b, c->c, ibuff[idx * 16 + 4], 11, g_t[37]);
	R3O(c->c, c->d, c->a, c->b, ibuff[idx * 16 + 7], 16, g_t[38]);
	R3O(c->b, c->c, c->d, c->a, ibuff[idx * 16 + 10], 23, g_t[39]);
	R3O(c->a, c->b, c->c, c->d, ibuff[idx * 16 + 13], 4, g_t[40]);
	R3O(c->d, c->a, c->b, c->c, ibuff[idx * 16 + 0], 11, g_t[41]);
	R3O(c->c, c->d, c->a, c->b, ibuff[idx * 16 + 3], 16, g_t[42]);
	R3O(c->b, c->c, c->d, c->a, ibuff[idx * 16 + 6], 23, g_t[43]);
	R3O(c->a, c->b, c->c, c->d, ibuff[idx * 16 + 9], 4, g_t[44]);
	R3O(c->d, c->a, c->b, c->c, ibuff[idx * 16 + 12], 11, g_t[45]);
	R3O(c->c, c->d, c->a, c->b, ibuff[idx * 16 + 15], 16, g_t[46]);
	R3O(c->b, c->c, c->d, c->a, ibuff[idx * 16 + 2], 23, g_t[47]);
}

void	round4(t_md5_ctx *c, size_t idx)
{
	uint32_t *ibuff;

	ibuff = (uint32_t*)c->buff;
	R4O(c->a, c->b, c->c, c->d, ibuff[idx * 16 + 0], 6, g_t[48]);
	R4O(c->d, c->a, c->b, c->c, ibuff[idx * 16 + 7], 10, g_t[49]);
	R4O(c->c, c->d, c->a, c->b, ibuff[idx * 16 + 14], 15, g_t[50]);
	R4O(c->b, c->c, c->d, c->a, ibuff[idx * 16 + 5], 21, g_t[51]);
	R4O(c->a, c->b, c->c, c->d, ibuff[idx * 16 + 12], 6, g_t[52]);
	R4O(c->d, c->a, c->b, c->c, ibuff[idx * 16 + 3], 10, g_t[53]);
	R4O(c->c, c->d, c->a, c->b, ibuff[idx * 16 + 10], 15, g_t[54]);
	R4O(c->b, c->c, c->d, c->a, ibuff[idx * 16 + 1], 21, g_t[55]);
	R4O(c->a, c->b, c->c, c->d, ibuff[idx * 16 + 8], 6, g_t[56]);
	R4O(c->d, c->a, c->b, c->c, ibuff[idx * 16 + 15], 10, g_t[57]);
	R4O(c->c, c->d, c->a, c->b, ibuff[idx * 16 + 6], 15, g_t[58]);
	R4O(c->b, c->c, c->d, c->a, ibuff[idx * 16 + 13], 21, g_t[59]);
	R4O(c->a, c->b, c->c, c->d, ibuff[idx * 16 + 4], 6, g_t[60]);
	R4O(c->d, c->a, c->b, c->c, ibuff[idx * 16 + 11], 10, g_t[61]);
	R4O(c->c, c->d, c->a, c->b, ibuff[idx * 16 + 2], 15, g_t[62]);
	R4O(c->b, c->c, c->d, c->a, ibuff[idx * 16 + 9], 21, g_t[63]);
}

void	ft_md5_process(t_md5_ctx *ctx, uint32_t *digest)
{
	uint32_t	reg[4];
	int			i;

	i = 0;
	while (i < (ctx->buff_size / 64))
	{
		reg[0] = ctx->a;
		reg[1] = ctx->b;
		reg[2] = ctx->c;
		reg[3] = ctx->d;
		round1(ctx, i);
		round2(ctx, i);
		round3(ctx, i);
		round4(ctx, i);
		ctx->a = reg[0] + ctx->a;
		ctx->b = reg[1] + ctx->b;
		ctx->c = reg[2] + ctx->c;
		ctx->d = reg[3] + ctx->d;
		i++;
	}
	digest[0] = ctx->a;
	digest[1] = ctx->b;
	digest[2] = ctx->c;
	digest[3] = ctx->d;
}
