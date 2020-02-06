/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnita <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 20:33:03 by pnita             #+#    #+#             */
/*   Updated: 2019/04/06 20:33:04 by pnita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	if (dst == src)
		return (dst);
	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	if (s < d && d < s + len)
	{
		i = len - 1;
		while (i != 0)
		{
			d[i] = s[i];
			i--;
		}
		d[i] = s[i];
	}
	else
		ft_memcpy(d, s, len);
	return (dst);
}
