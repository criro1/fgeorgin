/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_varg_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 15:54:55 by mwuckert          #+#    #+#             */
/*   Updated: 2019/09/13 12:58:29 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_varg_c(t_print *sp)
{
	if ((*CAST_L(sp->arg) = (signed char)va_arg(sp->args, int)) < 0)
	{
		*CAST_UL(sp->arg) = (unsigned long)-*CAST_L(sp->arg);
		sp->format.flags |= 1;
	}
}
