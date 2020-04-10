/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:24:10 by mwuckert          #+#    #+#             */
/*   Updated: 2018/12/28 18:12:06 by mwuckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *s;

	if (!s1 || !s2 ||
			!(s = (char*)(ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (0);
	ft_strcpy(s, s1);
	ft_strcat(s, s2);
	return (s);
}
