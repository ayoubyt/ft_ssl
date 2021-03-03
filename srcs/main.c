/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoubyt <ayoubyt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 23:40:22 by ayoubyt           #+#    #+#             */
/*   Updated: 2021/03/03 02:34:37 by ayoubyt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"
#include <openssl/md5.h>
#include <time.h>

#define size 58547

int	main(int argc, char **argv)
{
	static unsigned char	s[size];
	unsigned char digest[16];

	srand(time(NULL));

	s[size] = 0;
	for (size_t i = 0; i < size; i++)
	{
		s[i] = rand() % 256;
	}


	ft_print_md5_digest(ft_md5(s, size));
	MD5(s, size, digest);

	printf("0x");
	for (size_t i = 0; i < 16; i++)
		printf("%x", digest[i]);
	printf("\n");
}
