/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_global.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguert <aaguert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 21:09:41 by ayoubyt           #+#    #+#             */
/*   Updated: 2021/03/10 17:34:26 by aaguert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GLOBAL_H
#define FT_GLOBAL_H

# include <stdlib.h>
# include <stdint.h>

# include "libft.h"

// rebverse 32 bit intiger byte order
# define REV32(x) (             \
	(((x)&0x000000FF) << 24) | \
	(((x)&0x0000FF00) << 8)  | \
	(((x)&0xFF000000) >> 24) | \
	(((x)&0x00FF0000) >> 8)    \
)

// rotate righ 32 bit intiger 'x' 'n' units
# define ROR32(x, n) (((x) >> (n)) | ((x) << (32 - (n))))

// shift right
# define SHR(x, n) ((x) >> (n))

typedef unsigned char byte_t;
typedef uint32_t word_t;

#endif
