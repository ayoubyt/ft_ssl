/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoubyt <ayoubyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 13:02:31 by ayoubyt           #+#    #+#             */
/*   Updated: 2021/03/11 13:24:19 by ayoubyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arg_parse.h"

args_t args;

static void print_usage()
{
	ft_putstr("./ft_ssl [COMMAND] [OPPTIONS]... [FILE]\n");
}

static void parse_command(int argc, char **argv)
{
	if (ft_strequ(argv[1], MD5CMD))
		args.cmd = MD5;
	else if (ft_strequ(argv[1], SHA256CMD))
		args.cmd = SHA256;
	else
	{
		ft_putstr_fd("error : unkown command ", 2);
		ft_putendl_fd(argv[1], 2);
		exit(EXIT_FAILURE);
	}

}

void ft_argparse(int argc, char **argv)
{
	if (argc == 1)
	{
		print_usage();
	}
	else
	{
		parse_command(argc, argv);
	}
}
