/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_num_to_buf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 19:51:02 by mwuckert          #+#    #+#             */
/*   Updated: 2019/07/21 15:35:08 by mwuckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_add_row_num_to_buf(t_print *sp, char *num)
{
	char c;

	c = *CAST_UL(sp->arg) % sp->format.len.base;
	if (*CAST_UL(sp->arg) > sp->format.len.base - 1)
	{
		*CAST_UL(sp->arg) /= sp->format.len.base;
		ft_add_row_num_to_buf(sp, num);
	}
	sp->format.str = num + c;
	ft_add_to_buf(sp);
}

void		ft_add_num_to_buf(t_print *sp)
{
	char	*num;

	num = TYPES[sp->format.types] == 'X' ? BASE_UPPER : BASE_LOWER;
	ft_add_row_num_to_buf(sp, num);
}
