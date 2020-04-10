/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_basic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 18:40:00 by mwuckert          #+#    #+#             */
/*   Updated: 2019/07/23 20:28:06 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_format_basic(t_print *sp)
{
	if (*sp->format.str)
	{
		sp->format.len.num = 1;
		ft_calculate_width(sp);
		sp->format.save = sp->format.str;
		if (!IS_MINUS(sp->format.flags))
			ft_add_space_to_buf(sp);
		ft_add_zero_to_buf(sp);
		sp->format.str = sp->format.save;
		ft_add_to_buf(sp);
		ft_add_space_to_buf(sp);
		sp->format.str = ++sp->format.save;
	}
}
