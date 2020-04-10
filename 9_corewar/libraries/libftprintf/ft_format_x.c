/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 17:19:24 by mwuckert          #+#    #+#             */
/*   Updated: 2019/09/06 20:10:48 by mwuckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_format_x(t_print *sp)
{
	sp->format.len.base = 16;
	CAST_TFUNC(sp->format.func)[sp->format.len.flags + sp->format.size + 5](sp);
	if (*CAST_UL(sp->arg) || sp->format.precision)
		sp->format.len.num = ft_base_len(*CAST_UL(sp->arg), 16);
	ft_calculate_precision(sp);
	if (IS_SHARP(sp->format.flags) && *CAST_UL(sp->arg))
		sp->format.len.num += 2;
	ft_calculate_width(sp);
	sp->format.save = sp->format.str;
	if (!IS_MINUS(sp->format.flags))
		ft_add_space_to_buf(sp);
	if (IS_SHARP(sp->format.flags) && *CAST_UL(sp->arg))
	{
		sp->format.str = "0";
		ft_add_to_buf(sp);
		sp->format.str = &TYPES[sp->format.types];
		ft_add_to_buf(sp);
	}
	ft_add_zero_to_buf(sp);
	if (*CAST_UL(sp->arg) || sp->format.precision)
		ft_add_num_to_buf(sp);
	ft_add_space_to_buf(sp);
	sp->format.str = sp->format.save;
}
