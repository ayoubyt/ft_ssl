/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguert <aaguert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 23:40:22 by ayoubyt           #+#    #+#             */
/*   Updated: 2021/03/04 12:50:23 by aaguert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"
// #include <openssl/md5.h>
#include <time.h>

#define size 58547

int	main(int argc, char **argv)
{
	static unsigned char	s[size + 1];
	unsigned char digest[16];

	srand(time(NULL));

	s[size] = 0;
	for (size_t i = 0; i < size; i++)
	{
		s[i] = rand() % 256;
	}


	ft_print_md5_digest(ft_md5(s, size));

	// MD5(s, size, digest);
	// printf("0x");
	// for (size_t i = 0; i < 16; i++)
	// 	printf("%x", digest[i]);
	// printf("\n");
}
