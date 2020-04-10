/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_str_to_buf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 15:34:16 by mwuckert          #+#    #+#             */
/*   Updated: 2019/07/23 14:28:51 by mwuckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_add_str_to_buf(t_print *sp)
{
	while (*sp->format.str)
	{
		ft_add_to_buf(sp);
		++sp->format.str;
	}
}
