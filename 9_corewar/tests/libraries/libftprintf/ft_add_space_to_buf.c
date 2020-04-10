/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 16:15:14 by mwuckert          #+#    #+#             */
/*   Updated: 2019/07/16 17:44:23 by mwuckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_add_space_to_buf(t_print *sp)
{
	sp->format.str = " ";
	while (sp->format.len.space-- > 0)
		ft_add_to_buf(sp);
}
