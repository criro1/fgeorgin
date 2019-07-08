/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 17:37:29 by fgeorgin          #+#    #+#             */
/*   Updated: 2019/05/03 15:11:50 by fgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = -1;
	j = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[++i] != needle[0] && i < len)
		if (haystack[i] == '\0')
			return (NULL);
	while (haystack[i] != '\0' && i < len)
	{
		while (haystack[i + j] == needle[j] && i + j < len)
		{
			if (needle[j + 1] == '\0' && haystack[i + j] == needle[j])
				return ((char*)haystack + i);
			if (haystack[i + j + 1] != needle[j + 1])
				break ;
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}
