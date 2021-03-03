/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoubyt <ayoubyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 21:09:57 by ayoubyt           #+#    #+#             */
/*   Updated: 2021/03/02 23:15:20 by ayoubyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_MD5_H
#define FT_MD5_H

#include "ft_global.h"

#define F(x, y, z) (((x) & (y)) | ((~x) & (z)))
#define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | (~z)))

/*
** rotate left
*/

 #define RL(w,s) ((w << s) | ((w & 0xFFFFFFFF) >> (32 - s)))

/*
** R{n}D : round 'n' operation
*/

#define R1O(a, b, c, d, x, s, t) (a = b + RL((a + F(b, c, d) + x + t), s))
#define R2O(a, b, c, d, x, s, t) (a = b + RL((a + G(b, c, d) + x + t), s))
#define R3O(a, b, c, d, x, s, t) (a = b + RL((a + H(b, c, d) + x + t), s))
#define R4O(a, b, c, d, x, s, t) (a = b + RL((a + I(b, c, d) + x + t), s))

typedef struct	s_md5_ctx
{
	uint32_t		a;
	uint32_t		b;
	uint32_t		c;
	uint32_t		d;
	unsigned char	*buff;
	size_t			buff_size;
}				t_md5_ctx;



uint32_t	*ft_md5(unsigned char *data, size_t len);
void		ft_md5_process(t_md5_ctx *ctx, uint32_t *digest);
void		ft_print_md5_digest(uint32_t *digest);

uint32_t	f(uint32_t x, uint32_t y, uint32_t z);
uint32_t	g(uint32_t x, uint32_t y, uint32_t z);
uint32_t	h(uint32_t x, uint32_t y, uint32_t z);
uint32_t	i(uint32_t x, uint32_t y, uint32_t z);

uint32_t	rl(uint32_t w, uint32_t s);
uint32_t	r1o(t_md5_ctx *ctx, uint32_t x, uint32_t s, uint32_t t);
uint32_t	r2o(t_md5_ctx *ctx, uint32_t x, uint32_t s, uint32_t t);
uint32_t	r3o(t_md5_ctx *ctx, uint32_t x, uint32_t s, uint32_t t);
uint32_t	r4o(t_md5_ctx *ctx, uint32_t x, uint32_t s, uint32_t t);

#endif
