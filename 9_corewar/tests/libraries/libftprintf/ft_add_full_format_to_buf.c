/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_full_format_to_buf.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 00:00:06 by mwuckert          #+#    #+#             */
/*   Updated: 2019/09/06 20:39:21 by mwuckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_add_full_format_to_buf(t_print *sp)
{
	sp->format.save = sp->format.str;
	if (!(sp->format.flags & 128))
		ft_add_space_to_buf(sp);
	ft_add_sign_to_buf(sp);
	ft_add_zero_to_buf(sp);
	ft_add_num_to_buf(sp);
	ft_add_space_to_buf(sp);
	sp->format.str = sp->format.save;
}
