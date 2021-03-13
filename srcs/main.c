/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoubyt <ayoubyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 23:40:22 by ayoubyt           #+#    #+#             */
/*   Updated: 2021/03/13 23:22:08 by ayoubyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_arg_parse.h"
#include "handlers.h"

int main(int argc, char **argv)
{
	ft_argparse(argc, argv);
	if (args.cmd == MD5 || args.cmd == SHA256)
		handle_hash();
}
