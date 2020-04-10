/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 17:21:03 by mwuckert          #+#    #+#             */
/*   Updated: 2019/09/13 15:22:51 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_format_u(t_print *sp)
{
	sp->format.len.base = 10;
	if (sp->format.types == 6)
		CAST_TFUNC(sp->format.func)
			[sp->format.len.flags + sp->format.size + 5](sp);
	else
		ft_varg_ul(sp);
	if (*CAST_UL(sp->arg) || sp->format.precision)
		sp->format.len.num = ft_base_len(*CAST_UL(sp->arg), 10);
	ft_calculate_precision(sp);
	ft_calculate_width(sp);
	sp->format.save = sp->format.str;
	if (!IS_MINUS(sp->format.flags))
		ft_add_space_to_buf(sp);
	ft_add_zero_to_buf(sp);
	if (*CAST_UL(sp->arg) || sp->format.precision)
		ft_add_num_to_buf(sp);
	ft_add_space_to_buf(sp);
	sp->format.str = sp->format.save;
}
