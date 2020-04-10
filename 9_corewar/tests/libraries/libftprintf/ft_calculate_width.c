/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_width.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 15:31:58 by mwuckert          #+#    #+#             */
/*   Updated: 2019/09/07 21:14:33 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_calculate_width(t_print *sp)
{
	if (sp->format.width > sp->format.len.num)
	{
		if (WRITE_ZERO(sp->format.flags) && sp->format.precision < 0)
			sp->format.len.zero = sp->format.width - sp->format.len.num;
		else
			sp->format.len.space = sp->format.width - sp->format.len.num;
	}
}
