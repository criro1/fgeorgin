/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 01:07:05 by fgeorgin          #+#    #+#             */
/*   Updated: 2020/03/17 01:07:08 by fgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char		*ft_strnct_fr(char *s1, const char *s2, size_t n)
{
	char	*new;
	size_t	i;
	size_t	k;

	k = -1;
	i = ft_strlen(s1) + ft_strlen(s2);
	if (!(new = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (s1[++k])
		new[k] = s1[k];
	i = 0;
	while (s2[i] && n--)
		new[k++] = s2[i++];
	new[k] = '\0';
	ft_memdel((void**)&s1);
	return (new);
}
