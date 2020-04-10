/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_varg_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 15:55:40 by wmaykit           #+#    #+#             */
/*   Updated: 2019/07/20 18:18:26 by mwuckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_varg_i(t_print *sp)
{
	if ((*CAST_L(sp->arg) = va_arg(sp->args, int)) < 0)
	{
		*CAST_UL(sp->arg) = -*CAST_L(sp->arg);
		sp->format.flags |= 1;
	}
}
