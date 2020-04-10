/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_sign_to_buf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 15:07:02 by wmaykit           #+#    #+#             */
/*   Updated: 2019/07/21 12:00:40 by mwuckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_add_sign_to_buf(t_print *sp)
{
	if (sp->format.flags & 1)
	{
		sp->format.str = "-";
		ft_add_to_buf(sp);
	}
	else if (sp->format.flags & 64)
	{
		sp->format.str = "+";
		ft_add_to_buf(sp);
	}
	else if (sp->format.flags & 32)
	{
		sp->format.str = " ";
		ft_add_to_buf(sp);
	}
}
