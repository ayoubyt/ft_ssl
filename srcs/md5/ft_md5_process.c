/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoubyt <ayoubyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 12:09:06 by ayoubyt           #+#    #+#             */
/*   Updated: 2021/03/02 13:37:19 by ayoubyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"
#include "ft_md5_constants.h"

void	round1(t_md5_ctx *ctx, size_t idx)
{
	R1O(ctx->a, ctx->b, ctx->c, ctx->d, ctx->buff[idx * 64 + 0], g_s[7], g_t[1]);
	R1O(ctx->d, ctx->a, ctx->b, ctx->c, ctx->buff[idx * 64 + 1], g_s[12], g_t[2]);
	R1O(ctx->c, ctx->d, ctx->a, ctx->b, ctx->buff[idx * 64 + 2], g_s[17], g_t[3]);
	R1O(ctx->b, ctx->c, ctx->d, ctx->a, ctx->buff[idx * 64 + 3], g_s[22], g_t[4]);
	R1O(ctx->a, ctx->b, ctx->c, ctx->d, ctx->buff[idx * 64 + 4], g_s[7], g_t[5]);
	R1O(ctx->d, ctx->a, ctx->b, ctx->c, ctx->buff[idx * 64 + 5], g_s[12], g_t[6]);
	R1O(ctx->c, ctx->d, ctx->a, ctx->b, ctx->buff[idx * 64 + 6], g_s[17], g_t[7]);
	R1O(ctx->b, ctx->c, ctx->d, ctx->a, ctx->buff[idx * 64 + 7], g_s[22], g_t[8]);
	R1O(ctx->a, ctx->b, ctx->c, ctx->d, ctx->buff[idx * 64 + 8], g_s[7], g_t[9]);
	R1O(ctx->d, ctx->a, ctx->b, ctx->c, ctx->buff[idx * 64 + 9], g_s[12], g_t[10]);
	R1O(ctx->c, ctx->d, ctx->a, ctx->b, ctx->buff[idx * 64 + 10], g_s[17], g_t[11]);
	R1O(ctx->b, ctx->c, ctx->d, ctx->a, ctx->buff[idx * 64 + 11], g_s[22], g_t[12]);
	R1O(ctx->a, ctx->b, ctx->c, ctx->d, ctx->buff[idx * 64 + 12], g_s[7], g_t[13]);
	R1O(ctx->d, ctx->a, ctx->b, ctx->c, ctx->buff[idx * 64 + 13], g_s[12], g_t[14]);
	R1O(ctx->c, ctx->d, ctx->a, ctx->b, ctx->buff[idx * 64 + 14], g_s[17], g_t[15]);
	R1O(ctx->b, ctx->c, ctx->d, ctx->a, ctx->buff[idx * 64 + 15], g_s[22], g_t[16]);
}


void	ft_md5_process(t_md5_ctx *ctx) {
	uint32_t	regs[4];
	int i;
	int j;

	i = 0;
	while (i < (ctx->buff_size / 64))
	{
	}

}
