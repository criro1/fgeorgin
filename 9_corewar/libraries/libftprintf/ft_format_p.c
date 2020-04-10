/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 20:07:31 by mwuckert          #+#    #+#             */
/*   Updated: 2019/09/06 20:07:47 by mwuckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_format_p(t_print *sp)
{
	sp->format.len.base = 16;
	*CAST_UL(sp->arg) = (unsigned long)va_arg(sp->args, void *);
	if (*CAST_UL(sp->arg) || sp->format.precision)
		sp->format.len.num = ft_base_len(*CAST_UL(sp->arg), 16);
	ft_calculate_precision(sp);
	sp->format.len.num += 2;
	ft_calculate_width(sp);
	sp->format.save = sp->format.str;
	if (!IS_MINUS(sp->format.flags))
		ft_add_space_to_buf(sp);
	sp->format.str = "0x";
	ft_add_str_to_buf(sp);
	ft_add_zero_to_buf(sp);
	if (*CAST_UL(sp->arg) || sp->format.precision)
		ft_add_num_to_buf(sp);
	ft_add_space_to_buf(sp);
	sp->format.str = sp->format.save;
}
