/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 20:52:34 by astamm            #+#    #+#             */
/*   Updated: 2019/11/03 18:49:55 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static int	ft_check_static(char **sta, int size, int fd, char *buf)
{
	char *addr;

	if (*sta == 0 || ft_strcmp(*sta, "") == 0)
	{
		size = read(fd, buf, BUFF_SIZE_GNL);
		if (size <= 0)
		{
			ft_memdel((void**)&buf);
			return (size == -1 ? -1 : 0);
		}
		buf[size] = '\0';
		addr = *sta;
		if (!(*sta = ft_strsub(buf, 0, size)))
		{
			ft_memdel((void**)&buf);
			return (-1);
		}
		ft_memdel((void**)&addr);
	}
	return (1);
}

static int	ft_supporting(char **sta, char *buf, int i, int size)
{
	char	*addr;

	buf[size] = '\0';
	addr = *sta;
	if (!(*sta = ft_strjoin(*sta, buf)))
	{
		ft_memdel((void**)&addr);
		return (-1);
	}
	ft_memdel((void**)&addr);
	return (--i);
}

static int	ft_supporting_2(char **sta, char **line, int i)
{
	char *addr;

	if (!(*line = ft_strsub(*sta, 0, i)))
		return (-1);
	addr = *sta;
	if (!(*sta = ft_strsub(*sta, i + 1, ft_strlen(*sta) - i - 1)))
	{
		ft_memdel((void**)&addr);
		return (-1);
	}
	ft_memdel((void**)&addr);
	return (1);
}

static int	ft_search_n(char **sta, char **line, char *buf, int fd)
{
	int		i;
	int		size;

	i = -1;
	size = 0;
	while (sta[0][++i] != '\n')
		if (sta[0][i] == '\0')
		{
			if ((size = read(fd, buf, BUFF_SIZE_GNL)) <= 0)
			{
				if (!(*line = ft_strsub(*sta, 0, i)))
					return (-1);
				ft_memdel((void**)sta);
				return (size == -1 ? -1 : 1);
			}
			if ((i = ft_supporting(sta, buf, i, size)) == -1)
				return (-1);
		}
	if (ft_supporting_2(sta, line, i) == -1)
		return (-1);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	char		*buf;
	static char	*sta[10240];
	int			size;

	size = 0;
	if (!line || fd < 0 || fd > 10240 || BUFF_SIZE_GNL < 1)
		return (-1);
	if (!(buf = ft_memalloc(BUFF_SIZE_GNL + 1)))
		return (-1);
	if ((size = ft_check_static(&sta[fd], size, fd, buf)) <= 0)
		return (size);
	if ((size = ft_search_n(&sta[fd], line, buf, fd)) == -1)
		ft_memdel((void**)sta);
	ft_memdel((void**)&buf);
	return (size);
}
