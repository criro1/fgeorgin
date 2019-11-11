/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_with_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnita <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 17:36:15 by pnita             #+#    #+#             */
/*   Updated: 2019/09/27 17:36:17 by pnita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		par_to_begin(t_par *par)
{
	par->minus = 0;
	par->plus = 0;
	par->space = 0;
	par->zero = 0;
	par->hash = 0;
	par->width = 0;
	par->pre = -1;
	par->length = NULL;
}

void		do_with_x_part_2(t_par par, char *hash, char *s, int *len)
{
	if (par.zero && par.pre < 0)
	{
		if (par.hash && ft_strcmp(s, "0"))
			join_to_buff(hash, -1, 0);
		join_num_of_c_to_buff('0', par.width - len[1]);
		join_to_buff(s, -1, 0);
	}
	else
	{
		join_num_of_c_to_buff(' ', par.width - len[1]);
		if (par.hash && ft_strcmp(s, "0"))
			join_to_buff(hash, -1, 0);
		join_num_of_c_to_buff('0', par.pre - len[0]);
		if (par.pre || ft_strcmp(s, "0"))
			join_to_buff(s, -1, 0);
	}
}

void		do_with_x(va_list arg, t_par par)
{
	uintmax_t	x;
	char		*s;
	int			len[2];
	char		*hash;

	x = 0;
	x = get_value_of_oux(arg, par);
	s = uitos_with_base(x, 16, ((par.type == 'X') ? 1 : 0));
	hash = (par.type == 'X') ? "0X" : "0x";
	len[0] = ft_strlen(s);
	len[1] = ((par.pre > len[0] || (!par.pre && !x)) ? par.pre : len[0])
		+ (par.hash && x ? 2 : 0);
	if (par.minus || par.width < 0)
	{
		if (par.hash && x)
			join_to_buff(hash, -1, 0);
		join_num_of_c_to_buff('0', par.pre - len[0]);
		if (par.pre || x)
			join_to_buff(s, -1, 0);
		join_num_of_c_to_buff(' ', (par.width < 0 ? -par.width : par.width)
			- len[1]);
	}
	else
		do_with_x_part_2(par, hash, s, len);
}

void		do_with_u_part_2(t_par par, uintmax_t u, char *s, int *len)
{
	if (par.zero && par.pre < 0)
	{
		join_num_of_c_to_buff('0', par.width - len[0]);
		join_to_buff(s, -1, 0);
	}
	else
	{
		join_num_of_c_to_buff(' ', par.width - len[1]);
		join_num_of_c_to_buff('0', par.pre - len[0]);
		if (par.pre || u)
			join_to_buff(s, -1, 0);
	}
}

void		do_with_u(va_list arg, t_par par)
{
	uintmax_t	u;
	char		*s;
	int			len[2];

	u = 0;
	u = get_value_of_oux(arg, par);
	s = uitos_with_base(u, 10, 0);
	len[0] = ft_strlen(s);
	len[1] = ((par.pre > len[0] || (!par.pre && !u)) ? par.pre : len[0]);
	if (par.minus || par.width < 0)
	{
		join_num_of_c_to_buff('0', par.pre - len[0]);
		if (par.pre || u)
			join_to_buff(s, -1, 0);
		join_num_of_c_to_buff(' ', (par.width < 0 ? -par.width : par.width)
			- len[1]);
	}
	else
		do_with_u_part_2(par, u, s, len);
}
