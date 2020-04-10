/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:15:23 by mwuckert          #+#    #+#             */
/*   Updated: 2019/07/22 17:24:07 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_format(t_print *sp)
{
	sp->format.len.zero = 0;
	sp->format.len.space = 0;
	sp->format.len.num = 0;
	CAST_TFUNC(sp->format.func)[sp->format.types](sp);
}
