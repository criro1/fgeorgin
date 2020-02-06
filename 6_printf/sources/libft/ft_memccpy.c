/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnita <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 20:29:13 by pnita             #+#    #+#             */
/*   Updated: 2019/04/06 20:29:15 by pnita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src,
	int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	delim;
	size_t			i;

	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	delim = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		if (d[i] == delim)
			return ((void*)dst + i + 1);
		i++;
	}
	return (0);
}
