/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:58:36 by mwuckert          #+#    #+#             */
/*   Updated: 2018/12/01 15:21:35 by mwuckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	int		i;

	if (!s || !(new = (char*)ft_memalloc(sizeof(*s) * ft_strlen(s) + 1)))
		return (0);
	i = -1;
	while (*(s + ++i))
		*(new + i) = f(i, *(s + i));
	*(new + i) = '\0';
	return (new);
}
