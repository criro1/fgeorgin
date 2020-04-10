/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_t_real.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 20:47:37 by wmaykit           #+#    #+#             */
/*   Updated: 2019/09/11 20:17:34 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_real			*ft_get_t_real(t_print *sp)
{
	t_ieee754	standart;

	ft_bzero(&standart, sizeof(t_ieee754));
	if (sp->format.size == 4)
	{
		PUT_D(standart.fbits) = va_arg(sp->args, double);
		standart.type = DOUBLE_T;
	}
	else if (sp->format.ld_size)
	{
		PUT_LD(standart.fbits) = va_arg(sp->args, long double);
		standart.type = LDOUBLE_T;
	}
	else
	{
		PUT_D(standart.fbits) = va_arg(sp->args, double);
		standart.type = DOUBLE_T;
	}
	return (ft_get_real_number(&standart));
}
