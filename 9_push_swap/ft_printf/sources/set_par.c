/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_par.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnita <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 17:38:44 by pnita             #+#    #+#             */
/*   Updated: 2019/09/27 17:38:47 by pnita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_atoi_here(char **str)
{
	char					*s;
	unsigned long long int	i;
	int						sign;
	int						sz;

	s = *str;
	sign = 1;
	if (*s == '-' || *s == '+')
		if (*(s++) == '-')
			sign = -1;
	i = 0;
	sz = 0;
	while (*s >= '0' && *s <= '9')
	{
		i = i * 10 + *(s++) - '0';
		++sz;
	}
	*str = s;
	return ((int)i * sign);
}

void		set_length(char **s, char *s_end, t_par *par)
{
	char *ptr;

	ptr = *s;
	while (ptr < s_end)
	{
		if (par->length)
			break ;
		if (!ft_strncmp(ptr, "hh", 2))
			par->length = "hh";
		else if (!ft_strncmp(ptr, "h", 1))
			par->length = "h";
		else if (!ft_strncmp(ptr, "ll", 2))
			par->length = "ll";
		else if (!ft_strncmp(ptr, "l", 1))
			par->length = "l";
		else if (!ft_strncmp(ptr, "L", 1))
			par->length = "L";
		else if (!ft_strncmp(ptr, "j", 1))
			par->length = "j";
		else if (!ft_strncmp(ptr, "z", 1))
			par->length = "z";
		++ptr;
	}
	*s = ptr;
}

void		set_width_pre_part_2(char **ptr, va_list arg, t_par *par)
{
	if (**ptr == '*' && *(*ptr - 1) != '.')
	{
		par->width = va_arg(arg, int);
		++*ptr;
	}
	if (**ptr == '.')
	{
		par->pre = 0;
		++*ptr;
	}
	if (**ptr == '*' && *(*ptr - 1) == '.')
	{
		par->pre = va_arg(arg, int);
		++*ptr;
	}
}

void		set_width_pre(char **s, char *s_end, va_list arg, t_par *par)
{
	char	*ptr;

	ptr = *s;
	while (ptr < s_end)
	{
		set_width_pre_part_2(&ptr, arg, par);
		if (ft_strchr("0123456789", *ptr))
		{
			if (*(ptr - 1) == '.')
				par->pre = ft_atoi_here(&ptr);
			else
				par->width = ft_atoi_here(&ptr);
		}
		else
			break ;
	}
	*s = ptr;
}

void		set_flags(char **s, char *s_end, t_par *par)
{
	char	*ptr;

	ptr = *s;
	while (ptr < s_end)
	{
		if (ft_strchr(".*123456789lhLjz", *ptr))
			break ;
		if (*ptr == '-')
			par->minus = 1;
		else if (*ptr == '+')
			par->plus = 1;
		else if (*ptr == ' ')
			par->space = 1;
		else if (*ptr == '0')
			par->zero = 1;
		else if (*ptr == '#')
			par->hash = 1;
		++ptr;
	}
	*s = ptr;
}
