/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 21:53:22 by fgeorgin          #+#    #+#             */
/*   Updated: 2019/03/20 22:16:41 by fgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define BUF_SIZE 4096

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

char	*ft_expand_str(char *string, char *buf)
{
	int		i;
	int		j;
	int		k;
	char	*result;

	i = 0;
	j = 0;
	k = 0;
	while (string[i] != '\0')
		i++;
	while (buf[j] != '\0')
		j++;
	result = (char *)malloc(sizeof(char *) * (i + j) + 1);
	while (k++ < i)
		result[k] = string[k];
	j = 0;
	while (buf[j++] != '\0')
	{
		result[k] = buf[j];
		k++;
	}
	result[k] = '\0';
	return (result);
}

int		main(int ac, char **av)
{
	int		fd;
	int		par;
	int		ret;
	char	buf[BUF_SIZE + 1];
	char	*string;

	string = (char *)malloc(sizeof(char));
	string[0] = '\0';
	if (ac < 2)
	{
		write(1, "Error", 5);
		return (0);
	}
	par = 1;
	while (par <= ac - 1)
	{
		fd = open(av[par], O_RDONLY);
		while ((ret = read(fd, buf, BUF_SIZE)) > 0)
			string = ft_expand_str(string, buf);
		ft_putstr(ft_create_arr(string));
		par++;
	}
	return (0);
}
