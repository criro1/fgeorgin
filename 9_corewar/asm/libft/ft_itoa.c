/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 18:54:09 by mwuckert          #+#    #+#             */
/*   Updated: 2018/12/04 19:44:05 by mwuckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		size;
	int		copy;
	char	*a;

	size = 2;
	copy = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	while ((n / 10 && size++))
		n /= 10;
	if (copy >= 0 && !(a = (char*)ft_memalloc(size--)))
		return (0);
	else if (copy < 0 && !(a = (char*)ft_memalloc(size + 1)))
		return (0);
	n = copy < 0 ? -copy : copy;
	if (copy < 0)
		*(a + 0) = '-';
	while (size-- && !(size == 0 && copy < 0))
	{
		*(a + size) = n % 10 + 48;
		n /= 10;
	}
	return (a);
}
