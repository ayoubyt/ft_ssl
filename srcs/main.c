/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoubyt <ayoubyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 23:40:22 by ayoubyt           #+#    #+#             */
/*   Updated: 2021/12/04 16:56:33 by ayoubyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_arg_parse.h"
#include "handlers.h"
#include "ft_global.h"
#include "ft_base64.h"

int main(int argc, char **argv)
{
	byte_t *data = ft_base64_encode("A", 1);
	print_base64(data, 1);
	// ft_argparse(argc, argv);
	// if (args.cmd == MD5 || args.cmd == SHA256)
	// 	handle_hash();
}

