/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 21:51:11 by mwuckert          #+#    #+#             */
/*   Updated: 2019/09/10 20:03:44 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftfloat.h"
#include "libft.h"

void	ft_parse_float(t_ieee754 *st, t_parts *r)
{
	*((unsigned*)r->mantis + 1) = *((unsigned*)st->fbits) << 9;
	r->exponent = (unsigned char)(*((unsigned*)st->fbits) >> 23);
	r->sign = *((unsigned*)st->fbits) >> 31;
	if (r->exponent == 255)
	{
		if (*((unsigned*)r->mantis + 1))
		{
			r->spec_value = NAN_VALUE;
			r->sign = 0;
		}
		else
			r->spec_value = INF_VALUE;
	}
	else if (!r->exponent)
	{
		if (*((unsigned*)r->mantis + 1))
		{
			r->spec_value = DENORM_VALUE;
			r->exponent -= 127;
		}
		else
			r->spec_value = ZERO_VALUE;
	}
	else
		r->exponent -= 127;
}
