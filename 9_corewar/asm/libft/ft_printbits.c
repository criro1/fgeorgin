/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 15:19:09 by mwuckert          #+#    #+#             */
/*   Updated: 2019/09/03 15:37:56 by mwuckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printbits(void *bits, int n)
{
	unsigned		mask;

	while (--n >= 0)
	{
		mask = 256;
		while (mask >>= 1)
		{
			if (mask & 8)
				ft_putchar(' ');
			ft_putnbr(*((unsigned char*)bits + n) & mask ? 1 : 0);
		}
		if (n)
			ft_putchar(' ');
	}
	ft_putchar('\n');
}
