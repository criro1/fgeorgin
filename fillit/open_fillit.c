/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_fdf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 13:15:09 by fgeorgin          #+#    #+#             */
/*   Updated: 2019/07/01 21:25:46 by fgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		ft_str(char *ch, int i)
{
	int		con; //connections
	int		sh; //sharps

	i = 0;
	con = 0;
	sh = 0;
	while (ch[i] != '\0')
	{
		if (ch[i] != '.' && ch[i] != '#')
			return (0);
		if (ch[i] == '#')
			sh++;
		if (ch[i] == '#' && ch[i - 1] == '#')
			con++;
		if (ch[i] == '#' && ch[i + 1] == '#')
			con++;
		if (ch[i] == '#' && ch[i + 4] == '#')
			con++;
		if (ch[i] == '#' && ch[i - 4] == '#')
			con++;
		i++;
	}
	if ((con == 6 || con == 8) && ft_strlen(ch) == 16 && sh == 4)
		return (1);
	return (0);
}

int		ft_val(char *ac)
{
	int		fd;
	char	*line;
	char	*ch;
	int		i;

	i = 0;
	fd = open(ac, O_RDONLY);
	ch = (char*)malloc(sizeof(char) * 1);
	while (get_next_line(fd, &line))
	{
		ch = ft_strjoin(ch, line);
		i++;
		if (i % 5 == 0)
		{
			if (ft_str(ch, i) == 0)
				return (0);
			free(ch);
			ch = (char*)malloc(sizeof(char) * 1);
		}
		free(line);
	}
	close(fd);
	return (1);
}

int		main(int av, char **ac)
{
	int		fd;
	char	*line;
	char	*ch;
	int		i;
	
	if (av != 2)
	{
		ft_putstr("no any file, try again\n");
		return (0);
	}
	if (ft_val(ac[1]) == 0)//checking, if the file is valid
	{
		ft_putstr("not valid file");
		return (0);
	}
	return (0);}
