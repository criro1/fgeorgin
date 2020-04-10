/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_treal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 16:45:37 by mwuckert          #+#    #+#             */
/*   Updated: 2019/08/12 19:08:14 by mwuckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftfloat.h"

void	ft_delete_treal(t_real *r)
{
	if (r)
	{
		if (r->integer && r->fractional)
		{
			ft_memdel((void**)&r->integer);
			ft_memdel((void**)&r->fractional);
		}
		ft_memdel((void**)&r);
	}
}
