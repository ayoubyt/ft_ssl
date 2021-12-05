/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_parse.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoubyt <ayoubyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:14:30 by aaguert           #+#    #+#             */
/*   Updated: 2021/12/05 19:18:34 by ayoubyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARG_PARSE_H
#define FT_ARG_PARSE_H

#include "libft.h"

// onw way hash
#define MD5CMD "md5"
#define SHA256CMD "sha256"

// encoding
#define BASE64CMD "base64"

typedef unsigned char bool_t;

typedef enum
{
	MD5,
	SHA256,
	BASE64
} command_t;

typedef struct string_node
{
	char *val;
	struct string_node *next;
} string_node_t;

typedef struct string_list
{
	string_node_t *head;
	string_node_t *tail;
} string_list_t;

typedef struct
{
	command_t cmd;
	bool_t q_opt;
	bool_t p_opt;
	bool_t r_opt;
	bool_t e_opt;
	bool_t d_opt;
	bool_t i_opt;
	bool_t o_opt;
	string_list_t s_opt_params;
	string_list_t files;
} args_t;

extern args_t args;

void ft_argparse(int argc, char **argv);

#endif
