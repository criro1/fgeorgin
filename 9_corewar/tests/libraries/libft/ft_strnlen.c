/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 14:25:23 by mwuckert          #+#    #+#             */
/*   Updated: 2019/07/12 16:49:23 by mwuckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strnlen(const char *str, int n)
{
	register char *ptr;

	ptr = (char*)str;
	while (*ptr && n-- > 0)
		++ptr;
	return (ptr - str);
}
