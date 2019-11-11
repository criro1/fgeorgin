/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 14:45:06 by fgeorgin          #+#    #+#             */
/*   Updated: 2019/05/17 19:36:52 by fgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_end(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	if (s[i] == '\0')
		return (s + i);
	return (s + i + 1);
}

static char		*ft_fill(char *s)
{
	int		i;
	char	*res;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	res = (char*)malloc(sizeof(char) * i + 1);
	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static int		ft_gnl(char **s, char **line)
{
	char	*arr;

	if (*s[0] == '\0')
		return (0);
	if (ft_strchr(*s, '\n'))
	{
		*line = ft_fill(*s);
		arr = ft_strdup(ft_end(*s));
		free(*s);
		*s = ft_strdup(arr);
		free(arr);
	}
	else
	{
		*line = ft_strdup(*s);
		ft_strdel(s);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	int			r;
	char		buf[BUFF_SIZE1 + 1];
	static char	*s[LIM];
	char		*arr;

	if (read(fd, buf, 0) < 0 || !line)
		return (-1);
	if (s[fd] == NULL)
		s[fd] = ft_strdup("");
	while (!(ft_strchr(s[fd], '\n')))
	{
		r = read(fd, buf, BUFF_SIZE1);
		buf[r] = '\0';
		if (r == 0)
			break ;
		arr = ft_strjoin(s[fd], buf);
		free(s[fd]);
		s[fd] = ft_strdup(arr);
		if (s[fd] == NULL)
			s[fd] = ft_strdup("");
		free(arr);
	}
	return (ft_gnl(&s[fd], line));
}
