/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_treal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 18:37:08 by mwuckert          #+#    #+#             */
/*   Updated: 2019/09/04 13:32:48 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftfloat.h"

t_real		*ft_create_treal(short integer, short fractional)
{
	t_real *real;

	if (!(real = ft_memalloc(sizeof(t_real))))
		return (NULL);
	if (!(real->integer = ft_memalloc(integer * 4))
			|| !(real->fractional = ft_memalloc(fractional * 4)))
	{
		free(real);
		ft_memdel((void**)&real->integer);
		ft_memdel((void**)&real->fractional);
		return (NULL);
	}
	return (real);
}
