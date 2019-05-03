/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funtions1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 22:12:41 by fgeorgin          #+#    #+#             */
/*   Updated: 2019/03/20 22:20:28 by fgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

char	ft_find_empty(char *buf)
{
	int i;

	i = 1;
	if (buf[i] >= '0' && buf[i] <= '9')
	{
		while (buf[i] >= '0' && buf[i] <= '9')
			i++;
	}
	i = i + 2;
	return (buf[i]);
}

char	*ft_xxx(char *buf, int **n, int line, char *str)
{
	int s;
	int max;
	int i;
	int r;
	int h;

	max = n[n[line][0]][n[line][1]];
	s = 0;
	while (str[s] != '\n')
		s++;
	h = ((n[line][0] * (s + 1) + n[line][1]));
	r = 0;
	while (r != max)
	{
		i = 0;
		while (i < max)
		{
			str[h - i] = ft_find_empty(buf);
			i++;
		}
		h = h - s - 1;
		r++;
	}
	return (str);
}

int		**ft_max(int **n, int line, int sym, int b)
{
	int imax;
	int jmax;
	int i;
	int j;

	i = line;
	while (--i >= 0)
	{
		j = sym;
		while (--j >= 0)
		{
			if (n[i][j] >= b)
			{
				b = n[i][j];
				imax = i;
				jmax = j;
			}
		}
	}
	n[line][0] = imax;
	n[line][1] = jmax;
	return (n);
}

int		ft_min(int left, int up, int upleft)
{
	int r;

	if (left < up)
		r = left;
	else
		r = up;
	if (r > upleft)
		r = upleft;
	r++;
	return (r);
}
