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

void ft_sha256_process(sha256_ctx_t *ctx, byte_t *digest)
{
	word_t w[64];
	word_t a, b, c, d, e, f, g, h;
	word_t tmp1, tmp2;

	for (size_t i = 0; i < ctx->buffsize / 64; i++)
	{
		// Preparing the message schedule
		for (size_t j = 0; j < 64; j++)
		{
			// sha256 uses big endian and host system is little endian
			// so we need to reverse bytes in order to use them with our constants, wich
			// our system stores them in little endian
			if (i < 16)
				w[i] = REV32((word_t)(ctx->buff + 64 * i) + j);
			else
				w[i] = SSIGMA1(w[j - 2]) + w[j - 7] + SSIGMA0(w[j - 15]) + w[j - 16];
		}
		a = ctx->h0;
		b = ctx->h1;
		c = ctx->h2;
		d = ctx->h3;
		e = ctx->h4;
		f = ctx->h5;
		g = ctx->h6;
		h = ctx->h7;
		for (size_t j = 0; j < 64; j++)
		{
			tmp1 = h + SIGMA1(e) + CH(e, f, g) + K[j] + w[j];
			tmp2 = SIGMA0(a) + MAJ(a, b, c);
			h = g;
			g = f;
			f = e;
			e = d + tmp1;
			d = c;
			c = b;
			b = a;
			a = tmp1 + tmp2;
		}
		ctx->h0 = ctx->h0 + a;
		ctx->h1 = ctx->h1 + b;
		ctx->h2 = ctx->h2 + c;
		ctx->h3 = ctx->h3 + d;
		ctx->h4 = ctx->h4 + e;
		ctx->h5 = ctx->h5 + f;
		ctx->h6 = ctx->h6 + g;
		ctx->h7 = ctx->h7 + h;
	}
}