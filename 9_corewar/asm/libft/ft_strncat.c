/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 19:04:46 by mwuckert          #+#    #+#             */
/*   Updated: 2020/03/03 20:05:15 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*new;
	size_t	i;
	size_t	k;

	i = 0;
	k = -1;
	while (s1[i])
		i++;
	while (s2[i])
		i++;
	if (!(new = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (s1[++k])
		new[k] = s1[k];
	i = 0;
	while (s2[i] && n--)
		new[k++] = s2[i++];
	new[k] = '\0';
	return (new);
}
