/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_precision.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 15:33:08 by mwuckert          #+#    #+#             */
/*   Updated: 2019/09/11 12:41:05 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_calculate_precision(t_print *sp)
{
	if (sp->format.precision > sp->format.len.num)
	{
		sp->format.len.zero = sp->format.precision - sp->format.len.num;
		sp->format.len.num = sp->format.precision;
	}
}
