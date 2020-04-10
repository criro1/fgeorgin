/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:30:19 by mwuckert          #+#    #+#             */
/*   Updated: 2018/12/28 22:35:21 by mwuckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *addr;

	addr = dst;
	while (*src && len--)
		*dst++ = *src++;
	while (!*src && len--)
		*dst++ = '\0';
	return (addr);
}
