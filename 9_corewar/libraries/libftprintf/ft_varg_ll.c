/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_varg_ll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 12:27:42 by mwuckert          #+#    #+#             */
/*   Updated: 2019/07/23 15:08:09 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_varg_ll(t_print *sp)
{
	if ((*CAST_LL(sp->arg) = (long long)va_arg(sp->args, long)) < 0)
	{
		*CAST_UL(sp->arg) = -*CAST_LL(sp->arg);
		sp->format.flags |= 1;
	}
}
