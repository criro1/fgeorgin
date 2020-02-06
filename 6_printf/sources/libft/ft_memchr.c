/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnita <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 21:06:27 by pnita             #+#    #+#             */
/*   Updated: 2019/04/07 21:06:29 by pnita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	mem;
	unsigned char	*str;
	size_t			i;

	str = (unsigned char*)s;
	mem = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == mem)
			return ((void*)(str + i));
		i++;
	}
	return (0);
}
