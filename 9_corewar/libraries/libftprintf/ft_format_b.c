/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 19:07:37 by mwuckert          #+#    #+#             */
/*   Updated: 2019/09/13 19:41:21 by mwuckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_add_bits_to_buf(t_print *sp, void *bits, int n)
{
	unsigned		mask;

	while (--n >= 0)
	{
		mask = 256;
		while (mask >>= 1)
		{
			if (mask & 8)
			{
				sp->format.str = " ";
				ft_add_to_buf(sp);
			}
			sp->format.str = *((unsigned char*)bits + n) & mask ? "1" : "0";
			ft_add_to_buf(sp);
		}
		if (n)
		{
			sp->format.str = " ";
			ft_add_to_buf(sp);
		}
	}
}

void		ft_format_b(t_print *sp)
{
	sp->format.save = sp->format.str;
	if (sp->format.precision < 0)
		sp->format.precision = 4;
	sp->format.len.num = sp->format.precision * 4 +
		(!sp->format.precision ? 0 : sp->format.precision / 4 - 1);
	if (IS_SHARP(sp->format.flags))
		sp->format.len.num += 1;
	ft_calculate_width(sp);
	if (!IS_MINUS(sp->format.flags))
		ft_add_space_to_buf(sp);
	if (IS_SHARP(sp->format.flags))
	{
		sp->format.str = "b";
		ft_add_to_buf(sp);
	}
	ft_add_bits_to_buf(sp, va_arg(sp->args, void*), sp->format.precision);
	ft_add_space_to_buf(sp);
	sp->format.str = sp->format.save;
}
