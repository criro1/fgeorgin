/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_undefined_behavior.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 19:32:02 by mwuckert          #+#    #+#             */
/*   Updated: 2019/09/08 19:38:35 by mwuckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_skip_undefined_behavior(t_print *sp)
{
	if (UNDEFINED_BEHAVIOR(sp->format.str))
		++sp->format.str;
}
