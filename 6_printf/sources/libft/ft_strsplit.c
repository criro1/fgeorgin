/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnita <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 18:20:40 by pnita             #+#    #+#             */
/*   Updated: 2019/04/12 18:20:41 by pnita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_delete(char ***a, int ai)
{
	while (ai >= 0)
	{
		free((*a)[ai]);
		--ai;
	}
	free(*a);
	*a = 0;
}

static char	**ft_massiv_alloc(char *s, char c)
{
	int		i;
	int		len;
	char	**a;

	i = 0;
	len = 0;
	if (s[i] != c)
		len++;
	i++;
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i - 1] == c)
			len++;
		i++;
	}
	a = (char**)malloc(sizeof(char*) * (len + 1));
	return (a);
}

static char	*ft_str_fill_in_split(char *s, int *i, char c)
{
	int		j;
	int		len;
	char	*a_i;

	len = ft_len_before_delim(s + *i, c);
	a_i = (char*)malloc(sizeof(char) * (len + 1));
	if (a_i)
	{
		j = 0;
		while (s[*i] != c && s[*i] != '\0')
		{
			a_i[j] = s[*i];
			(*i)++;
			j++;
		}
		a_i[j] = '\0';
	}
	return (a_i);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		ai;
	char	**a;

	if (s == 0 || !(a = ft_massiv_alloc((char*)s, c)))
		return (0);
	i = 0;
	ai = 0;
	while (s[i] != '\0')
	{
		if ((i == 0 && s[i] != c) || (s[i] != c && s[i - 1] == c))
		{
			a[ai] = ft_str_fill_in_split((char*)s, &i, c);
			if (!a[ai])
			{
				ft_delete(&a, ai);
				return (0);
			}
			ai++;
		}
		else
			i++;
	}
	a[ai] = 0;
	return (a);
}
