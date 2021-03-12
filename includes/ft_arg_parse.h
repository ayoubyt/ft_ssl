/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_parse.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguert <aaguert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:14:30 by aaguert           #+#    #+#             */
/*   Updated: 2021/03/12 16:26:24 by aaguert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARG_PARSE
#define FT_ARG_PARSE

#include "libft.h"

#define MD5CMD "md5"
#define SHA256CMD "sha256"

typedef unsigned char bool_t;

typedef enum
{
	MD5,
	SHA256
} command_t;

typedef struct
{
	char *val;
	t_string_node *next;
} t_string_node;

typedef struct
{
	t_string_node head;
	t_string_node tail;
} t_string_list;

typedef struct
{
	command_t		cmd;
	t_string_list	*s_opt_params;
	t_string_list	*files;
	bool_t			q_opt;
	bool_t			p_opt;
	bool_t			r_opt;
} args_t;

extern args_t args;

void ft_argparse(int argc, char **argv);

#endif
