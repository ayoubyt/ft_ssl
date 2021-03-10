/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha2.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoubyt <ayoubyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:42:44 by aaguert           #+#    #+#             */
/*   Updated: 2021/03/09 23:45:22 by ayoubyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHA2_H
#define FT_SHA2_H

#include "ft_global.h"

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

#endif
