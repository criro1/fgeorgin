/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnita <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 20:44:29 by pnita             #+#    #+#             */
/*   Updated: 2019/04/26 20:45:42 by pnita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *str)
{
	char *pstr;

	pstr = str;
	pstr = ft_strlowcase(pstr);
	if (*pstr >= 'a' && *pstr <= 'z')
		*pstr -= ' ';
	while (*pstr != '\0')
	{
		pstr++;
		if (*pstr >= 'a' && *pstr <= 'z'
				&& (*(pstr - 1) < 'a' || *(pstr - 1) > 'z')
				&& (*(pstr - 1) < '0' || *(pstr - 1) > '9')
				&& (*(pstr - 1) < 'A' || *(pstr - 1) > 'Z'))
			*pstr -= ' ';
	}
	return (str);
}
