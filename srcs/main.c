/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoubyt <ayoubyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 23:40:22 by ayoubyt           #+#    #+#             */
/*   Updated: 2021/03/10 22:05:23 by ayoubyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"
#include "ft_sha2.h"

int main(int argc, char **argv)
{
	// if (argc == 2)
	// ft_print_md5_digest(ft_md5((unsigned char *)argv[1], ft_strlen(argv[1])));
	if (argc == 2)
		ft_print_sha256_digest(ft_sha256((unsigned char *)argv[1], ft_strlen(argv[1])));
}
