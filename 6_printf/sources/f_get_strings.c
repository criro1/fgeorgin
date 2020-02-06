/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_get_strings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnita <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 17:52:48 by pnita             #+#    #+#             */
/*   Updated: 2019/09/27 17:52:50 by pnita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		len_of_s_b_zero(char *s)
{
	char *ptr;

	ptr = s + 1;
	while (*ptr)
	{
		*(ptr - 1) = 0;
		++ptr;
	}
	*(ptr - 1) = 0;
}

void		get_strings_lf_part_3(char *s_num, int e, t_par par)
{
	int		i;
	int		count_sz;

	i = e;
	while (i >= 0)
	{
		if (par.m[i--] == '1')
			str1_plus_str_num(par.s1, s_num);
		plus_n_of_s_to_s(s_num, 2);
	}
	len_of_s_b_zero(s_num);
	s_num[0] = '5';
	count_sz = 1;
	i = e + 1;
	while (i < 64)
	{
		if (par.m[i++] == '1')
			str2_plus_str_num(par.s2, s_num, count_sz);
		++count_sz;
		plus_n_of_s_to_s(s_num, 5);
	}
}

void		get_strings_lf_part_2(char *s_num, int e, t_par par)
{
	int		count_sz;
	int		i;

	count_sz = 0;
	s_to_pow_with_base_n(s_num, e, &count_sz);
	i = 0;
	while (i < 64)
	{
		if (par.m[i++] == '1')
			str2_plus_str_num(par.s2, s_num, count_sz);
		++count_sz;
		plus_n_of_s_to_s(s_num, 5);
	}
}

void		get_strings_lf(t_ld ld, t_par par)
{
	char	*s_num;
	int		e;
	int		i;

	s_num = ft_strnew(11461);
	e = ld.t_ma.e - 16383;
	s_num[0] = '1';
	if (e >= 63)
	{
		s_to_pow_with_base_n(s_num, e - 63, NULL);
		i = 63;
		while (i >= 0)
		{
			if (par.m[i--] == '1')
				str1_plus_str_num(par.s1, s_num);
			plus_n_of_s_to_s(s_num, 2);
		}
	}
	else if (e < 0)
		get_strings_lf_part_2(s_num, e, par);
	else
		get_strings_lf_part_3(s_num, e, par);
	ft_strdel(&s_num);
}
