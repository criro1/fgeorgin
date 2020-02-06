/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnita <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 16:41:12 by pnita             #+#    #+#             */
/*   Updated: 2019/07/27 16:41:14 by pnita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		join_to_buff(char *s, int s_len, char c)
{
	int	counter;

	if (s)
	{
		if (s_len < 0)
			while (*s)
				g_buff[g_size++] = *(s++);
		else
		{
			counter = 0;
			while (counter++ < s_len && *s)
				g_buff[g_size++] = *(s++);
		}
	}
	else
		g_buff[g_size++] = c;
	g_buff[g_size] = '\0';
}

void		join_num_of_c_to_buff(char c, int num)
{
	int counter;

	counter = 0;
	while (counter++ < num)
		join_to_buff(NULL, 0, c);
}

void		do_with_par(va_list arg, t_par par)
{
	if (par.type == '%')
		do_with_percent(par);
	if (par.type == 'c')
		do_with_c(arg, par);
	if (par.type == 's')
		do_with_s(arg, par);
	if (par.type == 'p')
		do_with_p(arg, par);
	if (par.type == 'i' || par.type == 'd' || par.type == 'D')
		do_with_i(arg, par);
	if (par.type == 'o' || par.type == 'O')
		do_with_o(arg, par);
	if (par.type == 'x' || par.type == 'X')
		do_with_x(arg, par);
	if (par.type == 'u' || par.type == 'U')
		do_with_u(arg, par);
	if (par.type == 'f' || par.type == 'F')
		do_with_f(arg, par);
	if (par.type == 't')
		tank_to_buff();
	if (par.type == 'a')
		animal_to_buff();
	if (par.type == 'w')
		welcome_to_buff();
}

void		get_par(char **str, va_list arg)
{
	char	*ptr;
	t_par	par;

	ptr = *str;
	par_to_begin(&par);
	while (*ptr && !ft_strchr("%cspidDoOuUxXfFtaw", *ptr))
		++ptr;
	if (*ptr)
	{
		par.type = *ptr;
		set_flags(str, ptr, &par);
		set_width_pre(str, ptr, arg, &par);
		set_length(str, ptr, &par);
		do_with_par(arg, par);
		*str = ++ptr;
	}
	else
		*str = ptr;
}

int			ft_printf(char *format, ...)
{
	va_list	arg;

	va_start(arg, format);
	g_size = 0;
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			get_par(&format, arg);
		}
		else
			join_to_buff(NULL, 0, *(format++));
	}
	write(1, g_buff, g_size);
	va_end(arg);
	return (g_size);
}
