/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uitls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguert <aaguert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 16:58:02 by aaguert           #+#    #+#             */
/*   Updated: 2021/03/14 17:08:29 by aaguert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_global.h"

void	ft_print_byte(byte_t b)
{
		static char letters[] = {'a', 'b', 'c', 'd', 'e', 'f'};
		byte_t i1, i2;

		i1 = (b & 0xF0) >> 4;
		i2 = b & 0x0F;
		if (i1  < 10)
			ft_putnbr(i1);
		else
			ft_putchar(letters[i1 % 10]);
		if (i2  < 10)
			ft_putnbr(i2);
		else
			ft_putchar(letters[i2 % 10]);
}