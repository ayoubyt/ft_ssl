/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguert <aaguert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 13:02:31 by ayoubyt           #+#    #+#             */
/*   Updated: 2021/12/11 10:45:32 by aaguert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arg_parse.h"

args_t args = {
	0, 0, 0, 0, 0, 0, 0, 0, {0, 0}, {0, 0}};

void add_string_node(string_list_t *sl, char *str)
{
	string_node_t *node;

	node = malloc(sizeof(string_node_t));
	node->val = str;
	node->next = NULL;

	if (!sl->head)
		sl->head = sl->tail = node;
	else
	{
		sl->tail->next = node;
		sl->tail = sl->tail->next;
	}
}

void free_string_list(string_list_t *sl)
{
	string_node_t *tmp;

	while (sl->head)
	{
		tmp = sl->head;
		sl->head = sl->head->next;
		free(tmp);
	}
	sl->head = NULL;
	sl->tail = NULL;
}

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
	else if (ft_strequ(argv[1], BASE64CMD))
		args.cmd = BASE64;
	else
	{
		ft_putstr_fd("error : unkown command '", 2);
		ft_putstr_fd(argv[1], 2);
		ft_putendl_fd("'", 2);
		exit(EXIT_FAILURE);
	}
}

void parse_opts(int argc, char **argv)
{
	for (size_t i = 2; i < argc; i++)
	{
		if (argv[i][0] == '-')
		{
			int l = ft_strlen(argv[i]);
			for (size_t j = 1; j < l; j++)
			{
				switch (argv[i][j])
				{
				case 's':
					if (i + 1 >= argc || argv[i + 1][0] == '-')
					{
						ft_putstr_fd("error : must specify a string after '-s' flag\n", 2);
						print_usage();
						exit(EXIT_FAILURE);
					}
					else
					{
						add_string_node(&args.s_opt_params, argv[i + 1]);
						i++;
					}
					break;
				case 'p':
					args.p_opt = 1;
					break;
				case 'r':
					args.r_opt = 1;
					break;
				case 'q':
					args.q_opt = 1;
					break;
				case 'e':
					args.e_opt = 1;
					break;
				case 'd':
					args.d_opt = 1;
					break;
				case 'i':
					if (i + 1 >= argc || argv[i + 1][0] == '-')
					{
						ft_putstr_fd("error : must specify a file path or name after '-i' flag\n", 2);
						print_usage();
						exit(EXIT_FAILURE);
					}
					else
					{
						args.i_opt_param = argv[i + 1];
						i++;
					}
					break;
				case 'o':
					if (i + 1 >= argc || argv[i + 1][0] == '-')
					{
						ft_putstr_fd("error : must specify a file path or name after '-o' flag\n", 2);
						print_usage();
						exit(EXIT_FAILURE);
					}
					else
					{
						args.o_opt_param = argv[i + 1];
						i++;
					}
					break;
				default:
					ft_putstr_fd("unkown option -'", 2);
					ft_putchar_fd(argv[i][j], 2);
					ft_putendl_fd("'", 2);
				}
			}
		}
		else
			add_string_node(&args.files, argv[i]);
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
		parse_opts(argc, argv);
	}
}
