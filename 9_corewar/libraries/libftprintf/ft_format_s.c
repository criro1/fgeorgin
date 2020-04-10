/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 11:07:58 by mwuckert          #+#    #+#             */
/*   Updated: 2019/07/23 14:36:06 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_format_s(t_print *sp)
{
	char	*arg;

	if (!(arg = va_arg(sp->args, char*)))
		arg = "(null)";
	sp->format.save = sp->format.str;
	if (sp->format.width)
	{
		sp->format.len.num = ft_strnlen(arg, (sp->format.precision != -1)
				? sp->format.precision : sp->format.width);
		ft_calculate_width(sp);
		if (!(sp->format.flags & 136))
			ft_add_space_to_buf(sp);
		ft_add_zero_to_buf(sp);
	}
	sp->format.str = arg;
	if (sp->format.precision == -1)
		ft_add_str_to_buf(sp);
	else
		ft_add_strn_to_buf(sp);
	ft_add_space_to_buf(sp);
	sp->format.str = sp->format.save;
}
