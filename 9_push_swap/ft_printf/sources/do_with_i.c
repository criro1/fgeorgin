/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_with_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnita <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 17:29:16 by pnita             #+#    #+#             */
/*   Updated: 2019/09/27 17:29:19 by pnita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*itos_with_base(intmax_t n, int base)
{
	static char		*num_bukv;
	static char		buffer[50];
	char			*ptr;
	uintmax_t		num;

	num_bukv = "0123456789abcdef";
	num = ((n < 0) ? n * -1 : n);
	ptr = &buffer[49];
	*ptr = '\0';
	if (!num)
		return ("0");
	while (num != 0)
	{
		*--ptr = num_bukv[num % base];
		num /= base;
	}
	return (ptr);
}

intmax_t	get_value_of_i(va_list arg, t_par par)
{
	intmax_t	i;

	i = 0;
	if (par.type == 'D')
		i = (long)(va_arg(arg, long int));
	else if (par.length)
	{
		if (!ft_strncmp(par.length, "hh", 2))
			i = (signed char)(va_arg(arg, int));
		else if (!ft_strncmp(par.length, "h", 1))
			i = (short)(va_arg(arg, int));
		else if (!ft_strncmp(par.length, "l", 1))
			i = (long)(va_arg(arg, long int));
		else if (!ft_strncmp(par.length, "ll", 2))
			i = (long long)(va_arg(arg, long long int));
		else if (!ft_strncmp(par.length, "j", 1))
			i = (va_arg(arg, intmax_t));
		else if (!ft_strncmp(par.length, "z", 1))
			i = (size_t)(va_arg(arg, size_t));
	}
	else
		i = (int)(va_arg(arg, int));
	return (i);
}

char		set_i_sign(intmax_t i, t_par par)
{
	if (i < 0)
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

void		do_with_i_part_2(t_par par, char sign, char *s, int *len)
{
	if (par.zero && par.pre < 0)
	{
		if (sign)
			join_to_buff(NULL, 0, sign);
		join_num_of_c_to_buff('0', par.width - (sign ? 1 : 0) - len[0]);
		join_to_buff(s, -1, 0);
	}
	else
	{
		join_num_of_c_to_buff(' ', par.width - len[1]);
		if (sign)
			join_to_buff(NULL, 0, sign);
		join_num_of_c_to_buff('0', par.pre - len[0]);
		if (par.pre || ft_strcmp(s, "0"))
			join_to_buff(s, -1, 0);
	}
}

void		do_with_i(va_list arg, t_par par)
{
	intmax_t	i;
	char		sign;
	char		*s;
	int			len[2];

	i = 0;
	i = get_value_of_i(arg, par);
	sign = set_i_sign(i, par);
	s = itos_with_base(i, 10);
	len[0] = ft_strlen(s);
	len[1] = ((par.pre > len[0] || (!par.pre && !i)) ? par.pre : len[0])
		+ (sign ? 1 : 0);
	if (par.minus || par.width < 0)
	{
		if (sign)
			join_to_buff(NULL, 0, sign);
		join_num_of_c_to_buff('0', par.pre - len[0]);
		if (par.pre || i)
			join_to_buff(s, -1, 0);
		join_num_of_c_to_buff(' ', (par.width < 0 ? -par.width : par.width)
			- len[1]);
	}
	else
		do_with_i_part_2(par, sign, s, len);
}
