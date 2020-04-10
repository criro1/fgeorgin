/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 09:46:10 by mwuckert          #+#    #+#             */
/*   Updated: 2019/09/13 15:33:58 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_get_char(t_print *sp)
{
	sp->format.len.num = 0;
	if (sp->format.size == 2)
	{
		*CAST_US(sp->arg) = (unsigned short)va_arg(sp->args, int);
		sp->format.len.num = 2;
	}
	else
	{
		*CAST_C(sp->arg) = (char)va_arg(sp->args, int);
		sp->format.len.num = 1;
	}
}

static void	ft_add_char_to_buf(t_print *sp)
{
	sp->format.str = sp->arg;
	while (sp->format.len.num-- > 0)
	{
		ft_add_to_buf(sp);
		++sp->format.str;
	}
}

void		ft_format_c(t_print *sp)
{
	sp->format.save = sp->format.str;
	ft_get_char(sp);
	if ((sp->format.flags & 136) == 8)
		sp->format.len.zero = sp->format.width - sp->format.len.num;
	else
		sp->format.len.space = sp->format.width - sp->format.len.num;
	ft_add_zero_to_buf(sp);
	if (!(sp->format.flags & 136))
		ft_add_space_to_buf(sp);
	ft_add_char_to_buf(sp);
	ft_add_space_to_buf(sp);
	sp->format.str = sp->format.save;
}
