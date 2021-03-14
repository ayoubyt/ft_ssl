/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguert <aaguert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 22:33:27 by ayoubyt           #+#    #+#             */
/*   Updated: 2021/03/14 17:31:10 by aaguert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arg_parse.h"
#include "ft_md5.h"
#include "ft_sha2.h"

void print_hash(byte_t *data, size_t size)
{
	switch (args.cmd)
	{
	case MD5:
		ft_print_md5_digest(ft_md5(data, size));
		break;
	case SHA256:
		ft_print_sha256_digest(ft_sha256(data, size));
		break;
	}
}

void print_stdin_hash()
{
	char *input;

	input = ft_readall(0);
	ft_putendl(input);
	print_hash((byte_t*)input, ft_strlen(input));
	free(input);
	ft_putchar('\n');
}

void print_file_hash(char *filename)
{
	char *data;
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("error : ", 2);
		ft_putendl_fd(strerror(errno), 2);
		exit(EXIT_FAILURE);
	}
	data = ft_readall(fd);
	if (!args.r_opt)
	{
		if (args.cmd == MD5)
			ft_putstr("MD5 (");
		else if (args.cmd == SHA256)
			ft_putstr("SHA256 (");
		ft_putstr(filename);
		ft_putstr(") = ");
	}
	print_hash((byte_t*)data, ft_strlen(data));
	if (args.r_opt)
	{
		ft_putstr(" ");
		ft_putstr(filename);
	}
	ft_putchar('\n');
}

void print_string_hash(char *str)
{
	if (!args.r_opt)
	{
		if (args.cmd == MD5)
			ft_putstr("MD5 (\"");
		else if (args.cmd == SHA256)
			ft_putstr("SHA256 (\"");
		ft_putstr(str);
		ft_putstr("\") = ");
	}
	print_hash((byte_t*)str, ft_strlen(str));
	if (args.r_opt)
	{
		ft_putstr(" \"");
		ft_putstr(str);
		ft_putchar('"');
	}
	ft_putchar('\n');
}



void handle_hash(void)
{
	char *input;
	string_node_t *tmp;

	if (args.p_opt)
		print_stdin_hash();
	tmp = args.files.head;
	while (tmp)
	{
		print_file_hash(tmp->val);
		tmp = tmp->next;
	}
	tmp = args.s_opt_params.head;
	while (tmp)
	{
		print_string_hash(tmp->val);
		tmp = tmp->next;
	}
	if (!args.files.head && !args.s_opt_params.head && !args.p_opt)
		print_stdin_hash();
}
