/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_global.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoubyt <ayoubyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 21:09:41 by ayoubyt           #+#    #+#             */
/*   Updated: 2021/03/09 23:43:16 by ayoubyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GLOBAL_H
# define FT_GLOBAL_H

# include <stdlib.h>
# include <stdint.h>

# include "libft.h"

// reverses 32 bit intiger
#define REV32(n) (\
		(((n) & 0x000000FF) << 24) |\
		(((n) & 0x0000FF00) << 8) |\
		(((n) & 0x00FF0000) >> 8) |\
		(((n) & 0xFF000000) >> 24)\
		)

typedef uint8_t			byte_t;
typedef uint32_t		word_t;

#endif
