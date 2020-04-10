/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:45:21 by mwuckert          #+#    #+#             */
/*   Updated: 2018/12/07 20:48:39 by mwuckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (!(s1 || s2))
		return (0);
	while (n--)
	{
		if (!((unsigned char)*(unsigned char*)s1++ -
					(unsigned char)*(unsigned char*)s2++ == 0))
			return ((unsigned char)*(unsigned char*)(s1 - 1) -
					(unsigned char)*(unsigned char*)(s2 - 1));
	}
	return (0);
}
