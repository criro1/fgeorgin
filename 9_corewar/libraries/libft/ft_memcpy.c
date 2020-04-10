/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 21:23:52 by mwuckert          #+#    #+#             */
/*   Updated: 2018/12/07 16:13:28 by mwuckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t i;

	i = -1;
	if (!(dst || src))
		return (0);
	while (++i < n)
		*((unsigned char*)dst + i) = *((unsigned char*)src + i);
	return (dst);
}
