/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 05:19:30 by mwuckert          #+#    #+#             */
/*   Updated: 2019/09/13 18:39:44 by mwuckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		ft_continue(t_print *sp)
{
	if (*sp->format.str == 'j' || *sp->format.str == 'z')
	{
		sp->format.size = 4;
		++sp->format.str;
	}
}

void			ft_parse_size(t_print *sp)
{
	if (*sp->format.str == 'h')
	{
		if (*(sp->format.str + 1) == 'h' && (sp->format.size = 2))
			++sp->format.str;
		else if (sp->format.size <= 3)
			sp->format.size = 3;
		++sp->format.str;
	}
	else if (*sp->format.str == 'l')
	{
		if (*(sp->format.str + 1) == 'l' && (sp->format.size = 5))
			++sp->format.str;
		else
			sp->format.size = 4;
		++sp->format.str;
	}
	else if (*sp->format.str == 'L' && (sp->format.ld_size = 1))
		++sp->format.str;
	else
		ft_continue(sp);
}
