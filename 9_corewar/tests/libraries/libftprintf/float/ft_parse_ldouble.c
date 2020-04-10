/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_ldouble.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 21:51:58 by mwuckert          #+#    #+#             */
/*   Updated: 2019/09/13 18:56:56 by mwuckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftfloat.h"

void	ft_parse_ldouble(t_ieee754 *st, t_parts *r)
{
	*((unsigned*)r->mantis + 1) = *((unsigned*)st->fbits + 1) << 1;
	*((unsigned*)r->mantis + 1) |= *((unsigned*)st->fbits) >> 31;
	*((unsigned*)r->mantis) = *((unsigned*)st->fbits) << 1;
	r->exponent = (*((unsigned short*)st->fbits + 4) & ~32768);
	r->sign = *((unsigned short*)st->fbits + 4) >> 15;
	if (r->exponent == 32767)
	{
		if ((FC_U((r->mantis + 1)) || FC_U((r->mantis))) && !(r->sign = 0))
			r->spec_value = NAN_VALUE;
		else
			r->spec_value = INF_VALUE;
	}
	else if (!r->exponent)
	{
		if (*((unsigned*)r->mantis + 1) && *((unsigned*)r->mantis + 2))
		{
			r->spec_value = DENORM_VALUE;
			r->exponent -= 16383;
		}
		else
			r->spec_value = ZERO_VALUE;
	}
	else
		r->exponent -= 16383;
}
