/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 01:06:53 by fgeorgin          #+#    #+#             */
/*   Updated: 2020/03/17 01:06:56 by fgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char		*ft_strnjoin_free(char *s1, char const *s2)
{
	char	*s;
	size_t	n;

	n = 0;
	if (!s1 || !s2 ||
		!(s = (char*)ft_memalloc(sizeof(char) * (ft_strlen(s1) +
		ft_strlen(s2) + 1))))
		return (0);
	ft_strcpy(s, s1);
	while (s2[n] != '"')
		n++;
	s = ft_strnct_fr(s, s2, n + 1);
	ft_memdel((void**)&s1);
	return (s);
}
