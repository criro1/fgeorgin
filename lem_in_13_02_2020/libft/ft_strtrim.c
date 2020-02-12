/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 18:32:08 by fgeorgin          #+#    #+#             */
/*   Updated: 2019/05/02 23:32:41 by fgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (s == NULL)
		return (NULL);
	j = 0;
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j++;
	if (s[j] == '\0')
		return (ft_strdup(s + j));
	i = ft_strlen(s);
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t' || s[i] == '\0')
			&& i > 0)
		i--;
	str = ft_strsub(s, j, i - j + 1);
	return (str);
}
