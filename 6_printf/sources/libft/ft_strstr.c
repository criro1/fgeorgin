/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnita <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 20:26:27 by pnita             #+#    #+#             */
/*   Updated: 2019/04/11 20:26:29 by pnita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*h;

	h = (char*)haystack;
	len = ft_strlen(needle);
	if (!len)
		return (h);
	i = 0;
	while (h[i])
	{
		j = 0;
		while (needle[j] && needle[j] == h[i + j])
			++j;
		if (j == len)
			return (&h[i]);
		++i;
	}
	return (0);
}
