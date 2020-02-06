/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_with_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnita <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 17:33:22 by pnita             #+#    #+#             */
/*   Updated: 2019/09/27 17:33:24 by pnita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		tank_to_buff(void)
{
	char	*tank;

	tank = "█۞███████]▄▄▄▄▄▄▄▄▄▄▄\n"
		"▄▅█████████▅▄▃▂\n"
		"█★★RUSSIA★★█ █ ██████\n"
		"◥⊙▲⊙▲⊙▲⊙▲⊙▲⊙▲⊙◤";
	join_to_buff(tank, -1, 0);
}

char		*uitos_with_base(uintmax_t n, int base, char flag_big)
{
	static char		*num_little_bukv;
	static char		*num_big_bukv;
	char			*num_bukv;
	static char		buffer[50];
	char			*ptr;

	num_little_bukv = "0123456789abcdef";
	num_big_bukv = "0123456789ABCDEF";
	num_bukv = (!flag_big) ? num_little_bukv : num_big_bukv;
	ptr = &buffer[49];
	*ptr = '\0';
	if (!n)
		return ("0");
	while (n != 0)
	{
		*--ptr = num_bukv[n % base];
		n /= base;
	}
	return (ptr);
}

uintmax_t	get_value_of_oux(va_list arg, t_par par)
{
	uintmax_t	val;

	val = 0;
	if (par.type == 'U' || par.type == 'O')
		val = (unsigned long)(va_arg(arg, unsigned long int));
	else if (par.length)
	{
		if (!ft_strncmp(par.length, "hh", 2))
			val = (unsigned char)(va_arg(arg, unsigned int));
		else if (!ft_strncmp(par.length, "h", 1))
			val = (unsigned short)(va_arg(arg, unsigned int));
		else if (!ft_strncmp(par.length, "ll", 2))
			val = (unsigned long long)(va_arg(arg, unsigned long long int));
		else if (!ft_strncmp(par.length, "l", 1))
			val = (unsigned long)(va_arg(arg, unsigned long int));
		else if (!ft_strncmp(par.length, "j", 1))
			val = (va_arg(arg, intmax_t));
		else if (!ft_strncmp(par.length, "z", 1))
			val = (size_t)(va_arg(arg, size_t));
	}
	else
		val = (unsigned int)(va_arg(arg, unsigned int));
	return (val);
}

void		do_with_o_part_2(t_par par, uintmax_t o, char *s, int *len)
{
	if (par.zero && par.pre < 0)
	{
		if (par.hash && o)
			join_to_buff(NULL, 0, '0');
		join_num_of_c_to_buff('0', par.width - len[0]);
		join_to_buff(s, -1, 0);
	}
	else
	{
		join_num_of_c_to_buff(' ', par.width - len[1]);
		if (par.hash && o)
			join_to_buff(NULL, 0, '0');
		join_num_of_c_to_buff('0', par.pre - len[0]);
		if (par.pre || o || par.hash)
			join_to_buff(s, -1, 0);
	}
}

void		do_with_o(va_list arg, t_par par)
{
	uintmax_t	o;
	char		*s;
	int			len[2];

	o = 0;
	o = get_value_of_oux(arg, par);
	s = uitos_with_base(o, 8, ((par.type == 'O') ? 1 : 0));
	len[0] = ft_strlen(s) + (par.hash && o ? 1 : 0);
	len[1] = ((par.pre > len[0] || (!par.pre && !o && !par.hash))
		? par.pre : len[0]);
	if (par.minus || par.width < 0)
	{
		if (par.hash && o)
			join_to_buff(NULL, 0, '0');
		join_num_of_c_to_buff('0', par.pre - len[0]);
		if (par.pre || o || par.hash)
			join_to_buff(s, -1, 0);
		join_num_of_c_to_buff(' ', (par.width < 0 ? -par.width : par.width)
			- len[1]);
	}
	else
		do_with_o_part_2(par, o, s, len);
}
