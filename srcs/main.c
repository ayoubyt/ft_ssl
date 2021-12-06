/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguert <aaguert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 23:40:22 by ayoubyt           #+#    #+#             */
/*   Updated: 2021/12/06 10:03:55 by aaguert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_arg_parse.h"
#include "handlers.h"
#include "ft_global.h"
#include "ft_base64.h"

int main(int argc, char **argv)
{
	ft_argparse(argc, argv);
	if (args.cmd == MD5 || args.cmd == SHA256)
		handle_hash();
	else if (args.cmd == BASE64)
		handle_encoding();



	// char *data = ft_base64_encode(argv[1], ft_strlen(argv[1]));
	// ft_putendl(data);
	// free(data);
}

