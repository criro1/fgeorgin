/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_specifer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 06:10:58 by mwuckert          #+#    #+#             */
/*   Updated: 2019/09/07 20:55:17 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_format_specifer(t_print *sp)
{
	if ((ft_is_specifer(sp) && *sp->format.str &&
			sp->format.types == sp->format.len.flags)
				|| ft_isdigit(*sp->format.str))
		return (1);
	return (0);
}
