/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 20:16:15 by wmaykit           #+#    #+#             */
/*   Updated: 2019/09/12 23:56:08 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_set_params(t_print *sp, t_real *num)
{
	sp->format.len.base = 10;
	if (num->sign)
		sp->format.flags |= 1;
	if (IS_SIGN(sp->format.flags))
		++sp->format.len.num;
	if (*num->spec_value & 3)
		sp->format.len.num = 2 + (num->sign) ? 2 : 0;
	else
		sp->format.len.num += (num->len_int * 8) +
			((sp->format.precision > 0) ? sp->format.precision + 1 : 0) +
				ft_base_len(*(num->integer + num->len_int), 10);
	if (IS_SHARP(sp->format.flags) && !sp->format.precision)
		++sp->format.len.num;
	if (sp->format.width > sp->format.len.num)
	{
		if (WRITE_ZERO(sp->format.flags))
			sp->format.len.zero = sp->format.width - sp->format.len.num;
		else
			sp->format.len.space = sp->format.width - sp->format.len.num;
	}
}

void		ft_format_f(t_print *sp)
{
	t_real	*num;

	if (!(num = ft_get_t_real(sp)))
		return ;
	if (sp->format.precision < 0)
		sp->format.precision = 6;
	if (!(*num->spec_value & 3))
		ft_rounding_treal(num, sp->format.precision);
	ft_set_params(sp, num);
	sp->format.save = sp->format.str;
	if (!IS_MINUS(sp->format.flags))
		ft_add_space_to_buf(sp);
	ft_add_sign_to_buf(sp);
	ft_add_zero_to_buf(sp);
	ft_add_real_num_to_buf(num, sp);
	ft_add_space_to_buf(sp);
	sp->format.str = sp->format.save;
	ft_delete_treal(num);
}
