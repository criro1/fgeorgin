/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnita <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 20:18:16 by pnita             #+#    #+#             */
/*   Updated: 2019/04/11 20:18:18 by pnita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	value;
	char	*str;
	char	*return_ptr;

	value = (char)c;
	str = (char*)s;
	return_ptr = 0;
	while (*str != '\0')
	{
		if (*str == value)
			return_ptr = str;
		str++;
	}
	if (*str == value)
		return_ptr = str;
	return (return_ptr);
}
