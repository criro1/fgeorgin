/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_varg_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 19:41:56 by mwuckert          #+#    #+#             */
/*   Updated: 2019/07/23 15:05:56 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_varg_s(t_print *sp)
{
	if ((*CAST_S(sp->arg) = (short)va_arg(sp->args, int)) < 0)
	{
		*CAST_S(sp->arg) = -*CAST_S(sp->arg);
		sp->format.flags |= 1;
	}
}
