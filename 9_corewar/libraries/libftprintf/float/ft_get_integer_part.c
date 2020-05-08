/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_integer_part.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 19:45:05 by wmaykit           #+#    #+#             */
/*   Updated: 2020/04/21 21:31:04 by artem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftfloat.h"
#include "libft.h"

static void	ft_power_set(t_tmp *buf)
{
	buf->power = 32;
	buf->num[0] = 94967296;
	buf->num[1] = 42;
	buf->length = 2;
}

static void	ft_long_raise_to_power(t_tmp *buf, int power)
{
	int			diff;
	unsigned	*start;
	unsigned	*end;

	if (buf->power < 32)
		ft_power_set(buf);
	diff = power - buf->power;
	buf->power = power;
	while (diff--)
	{
		start = buf->num;
		end = buf->num + buf->length;
		while (start <= end)
			*start++ *= 2;
		ft_normalize_num(buf->num, &buf->length);
	}
}

static void	ft_quick_raise_to_power(t_tmp *buf, int power)
{
	buf->length = 1;
	buf->num[1] = 0;
	if ((buf->num[0] = 1 << power) >= BASE_LONG_NUM)
		ft_normalize_num(buf->num, &buf->length);
	buf->power = power;
}

static void	ft_raise_to_power(t_tmp *buf, int power)
{
	if (power < 32)
		ft_quick_raise_to_power(buf, power);
	else
		ft_long_raise_to_power(buf, power);
}

void		ft_get_integer_part(t_real *num, t_power *p)
{
	int		*power;
	t_tmp	buf;

	ft_bzero(&buf, sizeof(t_tmp));
	power = p->positive;
	num->len_int = 0;
	while (power >= p->powers)
	{
		ft_raise_to_power(&buf, *power);
		ft_addition_num(num->integer, buf.num, &num->len_int, &buf.length);
		--power;
	}
	while (num->len_int > 0 && !num->integer[num->len_int])
		--num->len_int;
	while (num->integer[num->len_int + 1])
		++num->len_int;
}
