/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnita <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 19:50:56 by pnita             #+#    #+#             */
/*   Updated: 2019/04/11 19:50:58 by pnita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	value;
	char	*str;

	value = (char)c;
	str = (char*)s;
	while (*str != '\0')
	{
		if (*str == value)
			return (str);
		str++;
	}
	if (*str == value)
		return (str);
	return (0);
}
