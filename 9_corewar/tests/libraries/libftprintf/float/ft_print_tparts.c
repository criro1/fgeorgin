/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tparts.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 17:19:06 by mwuckert          #+#    #+#             */
/*   Updated: 2019/09/03 15:28:07 by mwuckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftfloat.h"
#include "libft.h"

static void	ft_putspecvalue(unsigned value)
{
	if (value == NAN_VALUE)
		ft_putstr("NaN");
	else if (value == INF_VALUE)
		ft_putstr("inf");
	else if (value == ZERO_VALUE)
		ft_putstr("zero");
	else if (value == DENORM_VALUE)
		ft_putstr("denormalized");
	else if (!value)
		ft_putstr("No sign");
	ft_putchar('\n');
}

void		ft_print_tparts(t_parts *real)
{
	ft_putstr("sign:          ");
	real->sign ? ft_putstr("Yes") : ft_putstr("No");
	ft_putchar('\n');
	ft_putstr("exponent:      ");
	ft_putnbr(real->exponent);
	ft_putchar('\n');
	ft_putstr("mantis:        ");
	ft_printbits(real->mantis, 8);
	ft_putstr("special value: ");
	ft_putspecvalue(real->spec_value);
}
