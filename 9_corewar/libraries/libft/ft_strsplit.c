/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 18:44:00 by mwuckert          #+#    #+#             */
/*   Updated: 2019/11/03 18:58:29 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_strsplit(char const *s, char c)
{
	int		i;
	char	**ar;

	if (!s)
		return (0);
	i = 0;
	if (!(ar = (char**)ft_memalloc(sizeof(char*) * (ft_countwordc(s, c) + 1))))
		return (0);
	while (*s)
		if (*s != c)
		{
			if (!(*(ar + i++) = ft_strsub(s, 0, ft_strlenc(s, c))))
			{
				ft_twodarraydel((void**)ar);
				return (0);
			}
			s += ft_strlenc(s, c);
		}
		else
			s++;
	*(ar + i) = 0;
	return (ar);
}
