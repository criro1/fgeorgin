/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 04:32:49 by mwuckert          #+#    #+#             */
/*   Updated: 2019/07/22 17:11:48 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_parse_precision(t_print *sp)
{
	if (*sp->format.str == '.')
	{
		if (*++sp->format.str == '*')
		{
			sp->format.precision = va_arg(sp->args, int);
			++sp->format.str;
		}
		else if (ft_isdigit(*sp->format.str))
		{
			sp->format.precision = ft_atoi(sp->format.str);
			while (ft_isdigit(*sp->format.str))
				++sp->format.str;
		}
		else
			sp->format.precision = 0;
	}
}
