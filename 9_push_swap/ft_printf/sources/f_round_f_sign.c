/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_round.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnita <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 17:48:24 by pnita             #+#    #+#             */
/*   Updated: 2019/09/27 17:48:25 by pnita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		round_s1(char *s1)
{
	char	*s_tmp;

	s_tmp = s1;
	while (s_tmp < s1 + S1_SIZE && *s_tmp == '9')
		*(s_tmp++) = '0';
	*s_tmp = (!*s_tmp ? '0' : *s_tmp) + 1;
}

void		f_round_part_3(t_par par)
{
	char	*s_tmp;

	s_tmp = par.s2 + par.pre;
	if (*s_tmp >= '5' && *s_tmp <= '9')
	{
		while (--s_tmp >= par.s2 && *s_tmp == '9')
			*s_tmp = '0';
		if (s_tmp != par.s2 - 1)
			++*s_tmp;
		else
			round_s1(par.s1);
	}
}

void		f_round_part_2(t_par par)
{
	char	*s_tmp;

	if (*par.s2 == '5')
	{
		if (*par.s1 % 2)
		{
			s_tmp = par.s1;
			while (s_tmp < par.s1 + S1_SIZE && *s_tmp == '9')
				*(s_tmp++) = '0';
			*s_tmp = (!*s_tmp ? '0' : *s_tmp) + 1;
		}
		else
		{
			s_tmp = par.s2 + 1;
			while (*s_tmp == '0' && s_tmp < par.s2 + 13)
				++s_tmp;
			if (*s_tmp != '0')
				round_s1(par.s1);
		}
	}
	else if (*par.s2 >= '6' && *par.s2 <= '9')
		round_s1(par.s1);
}

void		f_round(t_par par)
{
	char	*s_tmp;

	if (par.pre == -1 || par.pre == 6)
	{
		s_tmp = par.s2 + 6;
		if (*s_tmp >= '5' && *s_tmp <= '9')
		{
			while (--s_tmp >= par.s2 && *s_tmp == '9')
				*s_tmp = '0';
			if (s_tmp != par.s2 - 1)
				++*s_tmp;
			else
				round_s1(par.s1);
		}
	}
	else if (!par.pre)
		f_round_part_2(par);
	else
		f_round_part_3(par);
}

char		set_f_sign(t_ld ld, t_par par)
{
	if (ld.t_ma.s)
		return ('-');
	else
	{
		if (par.plus)
			return ('+');
		else if (par.space)
			return (' ');
		else
			return (0);
	}
}
