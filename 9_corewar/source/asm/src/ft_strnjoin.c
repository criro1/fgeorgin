/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 16:27:26 by cwitting          #+#    #+#             */
/*   Updated: 2020/02/07 16:27:59 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char		*ft_strnjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	n;

	n = 0;
	if (!s1 || !s2 ||
			!(s = (char*)(ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (0);
	ft_strcpy(s, s1);
	while (s2[n] != '"')
		n++;
	ft_strncat(s, s2, n + 1);
	return (s);
}
