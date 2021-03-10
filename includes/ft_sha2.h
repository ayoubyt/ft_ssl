/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha2.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguert <aaguert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:42:44 by aaguert           #+#    #+#             */
/*   Updated: 2021/03/10 18:36:15 by aaguert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHA2_H
#define FT_SHA2_H

# include "ft_global.h"

typedef struct
{
	word_t h0;
	word_t h1;
	word_t h2;
	word_t h3;
	word_t h4;
	word_t h5;
	word_t h6;
	word_t h7;
	byte_t *buff;
	size_t buffsize;
} sha256_ctx_t;

# define CH(x, y, z) (((x) & (y)) | (~(x) & (z)))
# define MAJ(x, y, z) (((x) & (y)) | ((x) & (z)) | ((y) & (z)))
# define SIGMA0(x) (ROR32((x), 2) ^ ROR32((x), 13) ^ ROR32((x), 22))
# define SIGMA1(x) (ROR32((x), 6) ^ ROR32((x), 11) ^ ROR32((x), 25))

// small sigmas 'σ'
# define SSIGMA0(x) (ROR32((x), 7) ^ ROR32((x), 18) ^ SHR((x), 3))
# define SSIGMA1(x) (ROR32((x), 17) ^ ROR32((x), 19) ^ SHR((x), 10))

void	ft_sha256_process(sha256_ctx_t *ctx);
void	ft_print_sha256_digest(byte_t *digest);
byte_t	*ft_sha256(byte_t *data, size_t size);


#endif