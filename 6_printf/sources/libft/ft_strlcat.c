/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnita <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:59:54 by pnita             #+#    #+#             */
/*   Updated: 2019/04/11 17:59:56 by pnita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_d;
	size_t	len_s;

	len_d = ft_strlen(dst);
	len_s = ft_strlen(src);
	if (size <= len_d)
		return (size + len_s);
	else
	{
		i = 0;
		while (src[i] && i < size - len_d - 1)
		{
			dst[len_d + i] = src[i];
			i++;
		}
		dst[len_d + i] = '\0';
		return (len_d + len_s);
	}
}
