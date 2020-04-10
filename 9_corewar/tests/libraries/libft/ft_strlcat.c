/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:04:04 by mwuckert          #+#    #+#             */
/*   Updated: 2018/12/14 17:19:36 by mwuckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;

	i = ft_strlen(dst) + 1;
	if (size == 0)
		return (ft_strlen(src));
	else if (size < i)
		return (size + ft_strlen(src));
	if (i <= size)
		ft_strncat(dst, src, size - i);
	return ((i - 1) + ft_strlen(src));
}
