/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_varg_ull.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 19:20:40 by mwuckert          #+#    #+#             */
/*   Updated: 2019/07/20 20:10:53 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_varg_ull(t_print *sp)
{
	*CAST_ULL(sp->arg) = (unsigned long long)va_arg(sp->args, long);
}
