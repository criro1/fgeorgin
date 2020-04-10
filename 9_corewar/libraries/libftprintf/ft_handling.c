/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handling.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 21:26:08 by mwuckert          #+#    #+#             */
/*   Updated: 2019/09/06 20:38:37 by mwuckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_handling(t_print *sp)
{
	sp->format.len.flags = ft_strlen(TYPES);
	sp->format.func = (t_functions){FUNC};
	while (*sp->format.str)
	{
		if (*sp->format.str == '%')
		{
			ft_parse(sp);
			ft_format(sp);
		}
		else
		{
			ft_add_to_buf(sp);
			++sp->format.str;
		}
	}
}
