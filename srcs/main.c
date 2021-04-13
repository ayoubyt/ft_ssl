/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguert <aaguert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 23:40:22 by ayoubyt           #+#    #+#             */
/*   Updated: 2021/04/13 16:42:54 by aaguert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_arg_parse.h"
#include "handlers.h"
#include "ft_global.h"

int main(int argc, char **argv)
{
	ft_argparse(argc, argv);
	if (args.cmd == MD5 || args.cmd == SHA256)
		handle_hash();
}

