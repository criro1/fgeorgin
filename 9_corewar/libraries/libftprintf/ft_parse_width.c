/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 23:58:14 by mwuckert          #+#    #+#             */
/*   Updated: 2019/09/11 22:15:56 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_parse_width(t_print *sp)
{
	if (ft_isdigit(*sp->format.str))
	{
		if (!sp->format.width)
			sp->format.width = ft_atoi(sp->format.str);
		while (ft_isdigit(*sp->format.str))
			++sp->format.str;
	}
	else if (*sp->format.str == '*' && !ft_isdigit(*(sp->format.str + 1)))
	{
		if ((sp->format.width = va_arg(sp->args, int)) < 0)
		{
			sp->format.width = -sp->format.width;
			PUT_MINUS(sp->format.flags);
		}
		++sp->format.str;
	}
	else if (*sp->format.str == '*')
	{
		sp->format.width = va_arg(sp->args, int);
		sp->format.width = 0;
		++sp->format.str;
	}
}
