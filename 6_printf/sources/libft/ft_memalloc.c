/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnita <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 21:11:56 by pnita             #+#    #+#             */
/*   Updated: 2019/04/11 21:11:57 by pnita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void			*s;
	unsigned char	*ps;
	size_t			i;

	s = (void*)malloc(size);
	if (!s)
		return (0);
	ps = (unsigned char*)s;
	i = 0;
	while (i < size)
	{
		ps[i] = 0;
		i++;
	}
	return (s);
}
