/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_with_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnita <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 17:23:15 by pnita             #+#    #+#             */
/*   Updated: 2019/09/27 17:23:17 by pnita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		do_with_percent(t_par par)
{
	if (par.minus == 1)
	{
		join_to_buff(NULL, 0, '%');
		join_num_of_c_to_buff(' ', par.width - 1);
	}
	else
	{
		if (par.zero == 1)
			join_num_of_c_to_buff('0', par.width - 1);
		else
			join_num_of_c_to_buff(' ', par.width - 1);
		join_to_buff(NULL, 0, '%');
	}
}

void		do_with_c(va_list arg, t_par par)
{
	int	c;

	c = va_arg(arg, int);
	if (par.minus || par.width < 0)
	{
		join_to_buff(NULL, 0, c);
		join_num_of_c_to_buff(' ', (par.width < 0 ? -par.width : par.width)
			- 1);
		return ;
	}
	if (par.zero)
		join_num_of_c_to_buff('0', par.width - 1);
	else
		join_num_of_c_to_buff(' ', par.width - 1);
	join_to_buff(NULL, 0, c);
}

void		do_with_s(va_list arg, t_par par)
{
	char	*s;
	int		len;

	s = va_arg(arg, char*);
	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	len = ((par.pre < 0 || par.pre > len) ? len : par.pre);
	if (par.minus)
	{
		join_to_buff(s, par.pre, 0);
		join_num_of_c_to_buff(' ', par.width - len);
		return ;
	}
	if (par.zero)
		join_num_of_c_to_buff('0', par.width - len);
	else
		join_num_of_c_to_buff(' ', par.width - len);
	join_to_buff(s, par.pre, 0);
}

void		do_with_p_part_2(t_par par, char *s, int *len)
{
	if (par.zero && par.pre < 0)
		join_num_of_c_to_buff('0', par.width - len[1]);
	else
	{
		join_num_of_c_to_buff(' ', par.width - len[1]);
		join_to_buff("0x", -1, 0);
		join_num_of_c_to_buff('0', par.pre - len[0]);
	}
	if (ft_strcmp(s, "0") || par.pre)
		join_to_buff(s, -1, 0);
}

void		do_with_p(va_list arg, t_par par)
{
	char		*s;
	int			len[2];

	s = itos_with_base(va_arg(arg, intmax_t), 16);
	len[0] = (!ft_strcmp(s, "0") && !par.pre ? 0 : ft_strlen(s));
	len[1] = (par.pre > len[0] ? par.pre : len[0]) + 2;
	if (par.minus || par.zero)
		join_to_buff("0x", -1, 0);
	if (par.minus || par.width < 0)
	{
		join_num_of_c_to_buff(' ', par.pre - len[0]);
		if (ft_strcmp(s, "0") || par.pre)
			join_to_buff(s, -1, 0);
		join_num_of_c_to_buff(' ', (par.width < 0 ? -par.width : par.width)
			- len[1]);
	}
	else
		do_with_p_part_2(par, s, len);
}
