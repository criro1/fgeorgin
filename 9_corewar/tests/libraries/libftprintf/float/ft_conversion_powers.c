/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_powers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 16:31:08 by mwuckert          #+#    #+#             */
/*   Updated: 2019/08/31 10:56:43 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftfloat.h"

void	ft_conversion_powers(t_real *num, t_power *p)
{
	if (p->positive)
		ft_get_integer_part(num, p);
	if (p->negative)
		ft_get_frac_part(num, p);
}
