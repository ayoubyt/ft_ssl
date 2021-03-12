/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguert <aaguert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 13:02:31 by ayoubyt           #+#    #+#             */
/*   Updated: 2021/03/12 16:26:51 by aaguert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arg_parse.h"

args_t args = {
	0, 0, 0, 0, 0, 0
};

static void print_usage()
{
	ft_putstr("./ft_ssl [COMMAND] [-pqr] [-s string ...] [file ...]\n");
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

void parse_hash_opts(int argc, char **argv)
{
	for (size_t i = 1; i < argc; i++)
	{
		if (argv[i][0] == '-')
		{
			int l = ft_strlen(argv[i]);
			for (size_t j = 1; j < l; j++)
			{
				switch (argv[i][j])
				{
				case 's':
					if (i + 1 >= argc || argv[i + 1][0] == "-")
					{
						ft_putstr_fd("error : must specify a string after '-s' flag\n", 2);
						print_usage();
						exit(EXIT_FAILURE);
					}

					break;
				case 'p':
					args.p_opt = 1;
					break;
				case 'r':
					args.r_opt = 1;
					break;
				}
			}
		}
		else
		{
			if (args.cmd)
			{
				ft_putstr_fd("error : invalid input\n", 2);
				print_usage();
				exit(EXIT_FAILURE);
			}
			// else
			// 	args.s_opt_param = argv[i];
		}
	}
}

void ft_argparse(int argc, char **argv)
{
	if (argc == 1)
	{
		print_usage();
		exit(EXIT_SUCCESS);
	}
	else
	{
		parse_command(argc, argv);
		if (args.cmd == MD5 || args.cmd == SHA256)
			parse_hash_opts(argc, argv);
	}
}
