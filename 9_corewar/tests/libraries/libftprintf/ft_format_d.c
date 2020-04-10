/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 20:50:24 by mwuckert          #+#    #+#             */
/*   Updated: 2019/09/10 14:04:14 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_format_d(t_print *sp)
{
	sp->format.len.base = 10;
	CAST_TFUNC(sp->format.func)[sp->format.len.flags + sp->format.size](sp);
	if (*CAST_UL(sp->arg) || sp->format.precision)
		sp->format.len.num = ft_base_len(*CAST_UL(sp->arg), 10);
	ft_calculate_precision(sp);
	if (IS_SIGN(sp->format.flags))
		++sp->format.len.num;
	ft_calculate_width(sp);
	sp->format.save = sp->format.str;
	if (!IS_MINUS(sp->format.flags))
		ft_add_space_to_buf(sp);
	ft_add_sign_to_buf(sp);
	ft_add_zero_to_buf(sp);
	if (*CAST_UL(sp->arg) || sp->format.precision)
		ft_add_num_to_buf(sp);
	ft_add_space_to_buf(sp);
	sp->format.str = sp->format.save;
}
