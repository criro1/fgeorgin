/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnita <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 22:09:00 by pnita             #+#    #+#             */
/*   Updated: 2019/04/11 22:09:03 by pnita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	char	*str_after;
	int		i;

	if (!s || !f)
		return ((char*)ft_memalloc(1));
	str = (char*)s;
	if (!(str_after = ft_strnew(ft_strlen(str))))
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		str_after[i] = f(str[i]);
		i++;
	}
	str_after[i] = '\0';
	return (str_after);
}
