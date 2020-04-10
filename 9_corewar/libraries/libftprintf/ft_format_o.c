/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 17:18:00 by mwuckert          #+#    #+#             */
/*   Updated: 2019/09/13 15:32:42 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_set_params(t_print *sp)
{
	if (sp->format.precision)
		sp->format.len.num = ft_base_len(*CAST_UL(sp->arg), 8);
	else if (IS_SHARP(sp->format.flags))
		++sp->format.len.num;
	ft_calculate_precision(sp);
	ft_calculate_width(sp);
	if (IS_SHARP(sp->format.flags) && !sp->format.len.zero)
	{
		if (*CAST_UL(sp->arg))
		{
			sp->format.len.zero = 1;
			--sp->format.len.space;
		}
		else if (!sp->format.precision)
			sp->format.len.zero = 1;
	}
}

void		ft_format_o(t_print *sp)
{
	sp->format.len.base = 8;
	CAST_TFUNC(sp->format.func)[sp->format.len.flags + sp->format.size + 5](sp);
	ft_set_params(sp);
	sp->format.save = sp->format.str;
	if (!IS_MINUS(sp->format.flags))
		ft_add_space_to_buf(sp);
	ft_add_zero_to_buf(sp);
	if (sp->format.precision || *CAST_UL(sp->arg))
		ft_add_num_to_buf(sp);
	ft_add_space_to_buf(sp);
	sp->format.str = sp->format.save;
}
