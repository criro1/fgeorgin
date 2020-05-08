/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_frac_part.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 19:18:58 by wmaykit           #+#    #+#             */
/*   Updated: 2020/04/21 21:31:42 by artem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftfloat.h"
#include "libft.h"

static void		ft_power_set(t_tmp *buf)
{
	buf->power = 1;
	buf->num[0] = 5;
	buf->length = 1;
}

static void		ft_raise_power_five(t_tmp *buf, int power)
{
	int			diff;
	unsigned	*start;
	unsigned	*end;

	if (!buf->power)
		ft_power_set(buf);
	diff = power - buf->power;
	buf->power = power;
	while (diff--)
	{
		start = buf->num;
		end = buf->num + buf->length;
		while (start <= end)
			*start++ *= 5;
		ft_normalize_num(buf->num, &buf->length);
	}
}

void			ft_get_frac_part(t_real *num, t_power *p)
{
	t_tmp		buf;
	int			*power;

	ft_bzero(&buf, sizeof(t_tmp));
	power = p->negative;
	num->len_frac = 0;
	while (*power)
	{
		ft_raise_power_five(&buf, ABS(*power));
		ft_addition_num(num->fractional, buf.num, &num->len_frac, &buf.length);
		++power;
		ft_move_digit((num->fractional + num->len_frac),
				num->fractional, (ABS(*power)) - buf.power, &num->len_frac);
	}
	while (!num->fractional[num->len_frac])
		num->len_frac--;
	num->frac_position = num->len_frac;
	--power;
	num->len_frac = ABS(*power);
}
