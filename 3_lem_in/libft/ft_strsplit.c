/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 18:51:00 by fgeorgin          #+#    #+#             */
/*   Updated: 2019/05/02 23:24:42 by fgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_free(char **a, int len)
{
	len--;
	while (len >= 0)
	{
		free(a[len]);
		len--;
	}
	return (NULL);
}

static char		**ft_find(char **a, char const *s, char c)
{
	size_t i;
	size_t j;
	size_t len;

	i = 0;
	len = 0;
	while (s[i] != '\0')
	{
		while ((unsigned char)s[i] == (unsigned char)c && s[i] != '\0')
			i++;
		if (s[i] == '\0')
			break ;
		j = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		a[len] = ft_strsub(s, j, i - j);
		if (a[len] == NULL)
			return (ft_free(a, len));
		len++;
	}
	a[len] = NULL;
	return (a);
}

static int		ft_word(char const *s, char c)
{
	int i;
	int res;

	i = 0;
	res = 0;
	if (c == '\0')
		return (1);
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i + 1] == c)
			res++;
		else if (s[i] != c && s[i + 1] == '\0')
			res++;
		i++;
	}
	return (res);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**a;

	if (s == NULL)
		return (NULL);
	a = (char**)malloc(sizeof(char*) * ft_word(s, c) + 1);
	if (a == NULL)
		return (NULL);
	return (ft_find(a, s, c));
}
