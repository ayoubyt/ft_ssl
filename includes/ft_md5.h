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

#define RL(w, s) ((w << s) | (w) >> (32 - (s)))

/*
** R{n}D : round 'n' operation
*/

#define R1O(a, b, c, d, x, s, t) (a = b + RL((a + F(b, c, d) + x + t), s))
#define R2O(a, b, c, d, x, s, t) (a = b + RL((a + G(b, c, d) + x + t), s))
#define R3O(a, b, c, d, x, s, t) (a = b + RL((a + H(b, c, d) + x + t), s))
#define R4O(a, b, c, d, x, s, t) (a = b + RL((a + I(b, c, d) + x + t), s))

typedef struct	s_md5_ctx
{
	uint32_t	reg_a;
	uint32_t	reg_b;
	uint32_t	reg_c;
	uint32_t	reg_d;
	char		*buff;
	size_t		buff_size;
}				t_md5_ctx;



uint32_t *ft_md5(char *data, size_t len);

#endif
