/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funtions.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 22:04:07 by fgeorgin          #+#    #+#             */
/*   Updated: 2019/03/20 23:24:36 by fgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"
#include <stdlib.h>

char	ft_find_obstacle(char *buf)
{
	int i;

	i = 1;
	if (buf[i] >= '0' && buf[i] <= '9')
	{
		while (buf[i] >= '0' && buf[i] <= '9')
			i++;
	}
	i = i + 1;
	return (buf[i]);
}

int		**ft_num(char *buf, int **n, int sym, int b)
{
	int i;
	int j;
	int y;

	y = b + 1;
	i = 0;
	j = 0;
	while (buf[b + 1] != '\0' && ++b)
	{
		if (buf[b] == '\n' || buf[b] == '\0')
		{
			n[i++][j] = '\0';
			j = 0;
		}
		else if (buf[b] == ft_find_obstacle(buf))
			n[i][j++] = 0;
		else if (((b - y) % (sym + 1)) == 0 || (b < sym + y))
			n[i][j++] = 1;
		else
		{
			n[i][j] = ft_min(n[i][j - 1], n[i - 1][j], n[i - 1][j - 1]);
			j++;
		}
	}
	return (n);
}

char	*ft_fill_str(char *buf, char *str, int b)
{
	int i;

	i = 0;
	while (buf[b] != '\0')
	{
		str[i] = buf[b];
		i++;
		b++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_create_num(char *buf, int line, int sym, char *str)
{
	int **n;
	int b;

	n = (int **)malloc(sizeof(int *) * (line + 2));
	b = 0;
	while (b <= line)
	{
		n[b] = (int *)malloc(sizeof(int) * sym + 1);
		b++;
	}
	b = 0;
	while (buf[b] != '\n')
		b++;
	ft_num(buf, n, sym, b);
	ft_fill_str(buf, str, b + 1);
	b = 0;
	ft_max(n, line, sym, b);
	ft_xxx(buf, n, line, str);
	return (str);
}

char	*ft_create_arr(char *buf)
{
	int		line;
	int		sym;
	int		b;
	char	*str;

	line = 0;
	sym = 0;
	b = 0;
	while (buf[b] != '\n')
		b++;
	while (buf[++b] != '\n')
		sym++;
	while (buf[b] != '\0')
	{
		if (buf[b] == '\n')
			line++;
		b++;
	}
	str = (char *)malloc(sizeof(char) * (line * sym) + 1);
	if (buf[0] == '\0')
		return (str);
	ft_create_num(buf, line, sym, str);
	return (str);
}
