/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_varg_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 15:52:00 by wmaykit           #+#    #+#             */
/*   Updated: 2019/07/16 14:43:39 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_varg_l(t_print *sp)
{
	*CAST_L(sp->arg) = (long)va_arg(sp->args, long);
	if (*CAST_L(sp->arg) < 0)
	{
		*CAST_UL(sp->arg) = -*CAST_L(sp->arg);
		sp->format.flags |= 1;
	}
}
