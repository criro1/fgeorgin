/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 21:51:46 by mwuckert          #+#    #+#             */
/*   Updated: 2019/09/13 18:55:33 by mwuckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftfloat.h"
#include "libft.h"

void	ft_parse_double(t_ieee754 *st, t_parts *r)
{
	*((unsigned*)r->mantis + 1) = *((unsigned*)st->fbits + 1) << 12;
	*((unsigned short*)r->mantis + 2) |= *((unsigned*)st->fbits) >> 20;
	*((unsigned*)r->mantis) = *((unsigned*)st->fbits) << 12;
	r->exponent = (((*((unsigned *)st->fbits + 1) & ~2147483648) >> 20));
	r->sign = *((unsigned*)st->fbits + 1) >> 31;
	if (r->exponent == 2047)
	{
		if ((FC_U((r->mantis + 1)) || FC_U((r->mantis))) && !(r->sign = 0))
			r->spec_value = NAN_VALUE;
		else
			r->spec_value = INF_VALUE;
	}
	else if (!r->exponent)
	{
		if (*((unsigned*)r->mantis + 1) && *((unsigned short*)r->mantis + 2))
		{
			r->spec_value = DENORM_VALUE;
			r->exponent -= 1023;
		}
		else
			r->spec_value = ZERO_VALUE;
	}
	else
		r->exponent -= 1023;
}
