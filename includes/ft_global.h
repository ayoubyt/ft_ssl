/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_global.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoubyt <ayoubyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 21:09:41 by ayoubyt           #+#    #+#             */
/*   Updated: 2021/11/21 13:44:02 by ayoubyt          ###   ########.fr       */
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

typedef uint8_t byte_t;
typedef uint32_t word_t;

// must delete
void print_mem(unsigned char *data, size_t size);
void	ft_print_byte(byte_t b);

#endif
