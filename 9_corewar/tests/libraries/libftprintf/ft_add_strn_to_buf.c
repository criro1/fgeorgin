/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_strn_to_buf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 15:34:16 by mwuckert          #+#    #+#             */
/*   Updated: 2019/07/23 14:23:34 by mwuckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_add_strn_to_buf(t_print *sp)
{
	while (*sp->format.str && sp->format.precision--)
	{
		ft_add_to_buf(sp);
		++sp->format.str;
	}
}
