/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 21:42:16 by mwuckert          #+#    #+#             */
/*   Updated: 2019/09/10 18:32:52 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_parse(t_print *sp)
{
	++sp->format.str;
	sp->format.flags =
		sp->format.width =
			sp->format.ld_size = 0;
	sp->format.size = 1;
	sp->format.precision = -1;
	sp->format.types = sp->format.len.flags;
	ft_parse_flags(sp);
	ft_parse_width(sp);
	ft_parse_precision(sp);
	ft_parse_size(sp);
	ft_parse_types(sp);
	if (sp->format.types == sp->format.len.flags)
	{
		while (ft_format_specifer(sp))
		{
			ft_parse_flags(sp);
			ft_parse_width(sp);
			ft_parse_precision(sp);
			ft_parse_size(sp);
			ft_parse_types(sp);
			ft_skip_undefined_behavior(sp);
		}
	}
}
