/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoubyt <ayoubyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 22:33:27 by ayoubyt           #+#    #+#             */
/*   Updated: 2021/03/13 23:55:15 by ayoubyt          ###   ########.fr       */
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
	print_hash(input, ft_strlen(input));
	free(input);
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
	print_hash(data, ft_strlen(data));
	if (args.r_opt)
	{
		ft_putstr(" ");
		ft_putstr(filename);
	}
	printf("\n");
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
}
