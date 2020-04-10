/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_types.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 07:54:23 by mwuckert          #+#    #+#             */
/*   Updated: 2019/07/23 12:56:10 by mwuckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_parse_types(t_print *sp)
{
	if ((sp->format.types = ft_strchri(TYPES, *sp->format.str)) > -1)
		++sp->format.str;
	else
		sp->format.types = sp->format.len.flags;
}
