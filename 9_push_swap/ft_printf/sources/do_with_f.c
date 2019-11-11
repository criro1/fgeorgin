/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f2.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnita <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 17:43:04 by pnita             #+#    #+#             */
/*   Updated: 2019/09/27 17:43:06 by pnita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		plus_n_of_s_to_s(char *s, int n)
{
	char	*s_tmp;
	int		num;

	s_tmp = s;
	num = (*s_tmp - 48) * n;
	while (num || *s_tmp)
	{
		*(s_tmp++) = num % 10 + 48;
		num = num / 10 + (*s_tmp ? *s_tmp - 48 : 0) * n;
	}
}

void		s_to_pow_with_base_n(char *s, int pow, int *count_sz)
{
	int i;

	i = 0;
	if (pow > 0)
	{
		while (i < pow)
		{
			if (count_sz)
				++*count_sz;
			plus_n_of_s_to_s(s, 2);
			++i;
		}
	}
	else if (pow < 0)
	{
		while (i > pow)
		{
			if (count_sz)
				++*count_sz;
			plus_n_of_s_to_s(s, 5);
			--i;
		}
	}
}

void		nan_inf_to_buff(char *s, t_par par, char sign)
{
	int		len;
	char	*s_to_join;

	if (!ft_strcmp(s, "inf"))
		s_to_join = (par.type == 'F' ? "INF" : s);
	else
		s_to_join = (par.type == 'F' ? "NAN" : s);
	len = 3 + (!ft_strcmp(s, "inf") && sign ? 1 : 0);
	if (par.minus)
	{
		if (!ft_strcmp(s, "inf") && sign)
			join_to_buff(NULL, 0, sign);
		join_to_buff(s_to_join, -1, 0);
		join_num_of_c_to_buff(' ', par.width - len);
	}
	else
	{
		join_num_of_c_to_buff(' ', par.width - len);
		if (!ft_strcmp(s, "inf") && sign)
			join_to_buff(NULL, 0, sign);
		join_to_buff(s_to_join, -1, 0);
	}
}

void		do_with_f_part_2(t_par par, t_ld ld)
{
	char	sign;

	sign = set_f_sign(ld, par);
	if (ld.n && ld.n * 10 == ld.n)
		nan_inf_to_buff("inf", par, sign);
	else
	{
		par.m = ft_strnew(64);
		par.s1 = ft_strnew(S1_SIZE);
		*par.s1 = '0';
		par.s2 = create_str2(S2_SIZE);
		put_m_to_str(par, ld.t_ma.m);
		if (ld.n && ld.n != LDBL_MIN && ld.n != -LDBL_MIN)
			get_strings_lf(ld, par);
		f_to_buff(par, sign);
		ft_strdel(&par.m);
		ft_strdel(&par.s1);
		ft_strdel(&par.s2);
	}
}

void		do_with_f(va_list arg, t_par par)
{
	t_ld	ld;

	if (par.length && !ft_strcmp(par.length, "L"))
		ld.n = va_arg(arg, long double);
	else
		ld.n = va_arg(arg, double);
	if (ld.n != ld.n)
		nan_inf_to_buff("nan", par, 0);
	else
		do_with_f_part_2(par, ld);
}
