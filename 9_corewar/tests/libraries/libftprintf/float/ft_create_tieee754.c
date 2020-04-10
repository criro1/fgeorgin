/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_tieee754.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 16:24:04 by mwuckert          #+#    #+#             */
/*   Updated: 2019/09/03 18:17:54 by mwuckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftfloat.h"

t_ieee754	*ft_create_tieee754(int type)
{
	t_ieee754 *st;

	if (!(st = ft_memalloc(sizeof(t_ieee754))))
		return (0);
	(*st).type = type;
	return (st);
}
