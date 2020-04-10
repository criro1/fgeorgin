/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_digit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 15:19:57 by mwuckert          #+#    #+#             */
/*   Updated: 2019/09/03 17:02:04 by mwuckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_move_digit(unsigned *start, unsigned *end, int shift, int *len)
{
	unsigned *ten;
	unsigned *move;
	unsigned rdigit;
	unsigned ldigit;

	if (shift > 0)
	{
		ten = (unsigned[])
			{1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
		rdigit = ten[shift % 8];
		ldigit = ten[8 - shift % 8];
		move = start + (shift / 8);
		while (start >= end)
		{
			*(move + 1) += *start / ldigit;
			*move-- = *start % ldigit * rdigit;
			--start;
		}
		*(move + 1) += ++*start / ldigit;
		*move-- = *start / ldigit;
		while (move >= end)
			*move-- = 0;
		*len += shift / 8 + ((shift % 8) ? 1 : 0);
	}
}
