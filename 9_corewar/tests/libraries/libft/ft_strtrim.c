/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:14:28 by mwuckert          #+#    #+#             */
/*   Updated: 2018/12/04 01:58:39 by mwuckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	char	*str;

	if (!s)
		return (0);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	if (!*s && (str = ft_strdup("")))
		return (str);
	else if (!s)
		return (0);
	i = ft_strlen(s);
	while (*(s + i) == ' ' || *(s + i) == '\n'
			|| *(s + i) == '\t' || *(s + i) == '\0')
		i--;
	if (!(str = ft_strsub(s, 0, i + 1)))
		return (0);
	return (str);
}
