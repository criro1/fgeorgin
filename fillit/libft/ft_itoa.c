/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 20:28:33 by fgeorgin          #+#    #+#             */
/*   Updated: 2019/04/29 22:11:26 by fgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_dec(int len)
{
	int res;

	res = 1;
	while (len > 1)
	{
		res = res * 10;
		len--;
	}
	return (res);
}

static char		*ft_min_null(int n)
{
	char *b;

	b = ((n == 0) ? ft_memalloc(2) : ft_memalloc(12));
	if (n == 0)
	{
		b[0] = '0';
		b[1] = '\0';
	}
	else
	{
		b[0] = '-';
		b[1] = '2';
		b[2] = '1';
		b[3] = '4';
		b[4] = '7';
		b[5] = '4';
		b[6] = '8';
		b[7] = '3';
		b[8] = '6';
		b[9] = '4';
		b[10] = '8';
		b[11] = '\0';
	}
	return ((b == NULL) ? NULL : b);
}

static char		*ft_end(char *a, int i)
{
	a[i] = '\0';
	return (a);
}

char			*ft_itoa(int n)
{
	char	*a;
	int		c;
	int		len;
	int		i;

	if (n == 0 || n == -2147483648)
		return (ft_min_null(n));
	c = ((n < 0) ? -n : n);
	len = 1;
	while (c > 0 && len++)
		c = c / 10;
	a = ((n >= 0) ? ft_memalloc(len) : ft_memalloc(len + 1));
	if (a == NULL)
		return (NULL);
	if (n < 0)
		a[0] = '-';
	c = ((n < 0) ? -n : n);
	i = ((n < 0) ? 1 : 0);
	while (((n < 0) ? -n : n) > 0 && len--)
	{
		a[i] = (c / ft_dec(len) % 10) + 48;
		i++;
		n = n / 10;
	}
	return (ft_end(a, i));
}
