/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_real_num_to_buf.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 11:56:39 by wmaykit           #+#    #+#             */
/*   Updated: 2019/09/13 18:59:58 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_add_num_to_str(char *start, char *end, unsigned num)
{
	while (start >= end)
	{
		*start = '0' + num % 10;
		num /= 10;
		--start;
	}
}

static void	ft_add_big_num_to_buf(unsigned *start, unsigned *end, t_print *sp)
{
	*CAST_UL(sp->arg) = *start--;
	sp->format.len.base = 10;
	ft_add_num_to_buf(sp);
	*(sp->arg + 8) = 0;
	while (start >= end)
	{
		sp->format.str = sp->arg;
		ft_add_num_to_str(sp->arg + 7, sp->arg, *start);
		ft_add_str_to_buf(sp);
		--start;
	}
}

static void	ft_add_lim_precision_num_to_buf(t_real *n, t_print *sp, int tmp)
{
	unsigned	*start;
	unsigned	*end;
	unsigned	*b;

	start = n->fractional + n->frac_position;
	end = n->fractional + (tmp / 8) + 1;
	if (start >= end && *start)
		ft_add_big_num_to_buf(start, end, sp);
	b = (unsigned[]){DIGITS};
	*b = 1;
	sp->format.len.base = 10;
	if (--end == start && *end)
	{
		if ((*CAST_UL(sp->arg) = *end / b[tmp % 8]))
			ft_add_num_to_buf(sp);
	}
	else
	{
		sp->format.str = sp->arg;
		ft_add_num_to_str(sp->arg + 7, sp->arg, *end);
		*(sp->arg + (8 - tmp % 8)) = 0;
		ft_add_str_to_buf(sp);
	}
	sp->format.len.zero = 0;
}

static void	ft_add_fractional_to_buf(t_real *num, t_print *sp)
{
	int		sign_digit;

	sign_digit = 0;
	if (num->len_frac)
		sign_digit = ft_base_len(num->fractional[num->frac_position], 10) +
			num->frac_position * 8;
	if ((sp->format.len.zero = num->len_frac - sign_digit) < 0)
		sp->format.len.zero = 0;
	if (sp->format.len.zero >= sp->format.precision || !num->len_frac)
		sp->format.len.zero = sp->format.precision;
	sp->format.precision -= sp->format.len.zero;
	ft_add_zero_to_buf(sp);
	sp->format.len.zero = 0;
	if (num->len_frac && sp->format.len.zero < sp->format.precision)
	{
		if (sign_digit - sp->format.precision <= 0)
		{
			ft_add_big_num_to_buf(num->fractional + num->frac_position,
														num->fractional, sp);
			sp->format.len.zero = sp->format.precision - sign_digit;
		}
		else
			ft_add_lim_precision_num_to_buf(num, sp,
											sign_digit - sp->format.precision);
	}
}

void		ft_add_real_num_to_buf(t_real *num, t_print *sp)
{
	if (num)
	{
		if (*num->spec_value & 3)
		{
			sp->format.str = num->spec_value;
			ft_add_str_to_buf(sp);
		}
		else
		{
			if (num->integer)
				ft_add_big_num_to_buf(num->integer + num->len_int,
						num->integer, sp);
			if ((IS_SHARP(sp->format.flags) && !sp->format.precision)
					|| sp->format.precision)
			{
				sp->format.str = ".";
				ft_add_to_buf(sp);
			}
			if (sp->format.precision != 0 && num->fractional)
				ft_add_fractional_to_buf(num, sp);
			ft_add_zero_to_buf(sp);
		}
	}
}
