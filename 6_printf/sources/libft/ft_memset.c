/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnita <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 16:52:22 by pnita             #+#    #+#             */
/*   Updated: 2019/04/05 16:52:23 by pnita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *destination, int c, size_t n)
{
	unsigned char	*s;
	unsigned char	mem;
	size_t			i;

	s = (unsigned char*)destination;
	mem = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		*s = mem;
		s++;
		i++;
	}
	return (destination);
}
