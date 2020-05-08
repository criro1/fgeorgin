/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sstrcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 19:21:51 by cwitting          #+#    #+#             */
/*   Updated: 2020/03/03 19:28:46 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	ft_count(char *s1, const char *s2, size_t *n)
{
	int i;

	i = 0;
	while (s1[i])
		++i;
	while (s2[i] && (*n)--)
		++i;
	return (i);
}

char		*ft_sstrcat(char *s1, const char *s2, size_t n)
{
	char	*new;
	size_t	i;
	size_t	k;

	k = 0;
	i = ft_count(s1, s2, &n);
	if (!(new = (char*)malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = 0;
	while (s1[k])
	{
		new[i] = s1[k];
		i++;
		k++;
	}
	k = 0;
	while (s2[k])
	{
		new[i] = s2[k];
		i++;
		k++;
	}
	new[i] = '\0';
	return (new);
}
