/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 21:53:37 by fgeorgin          #+#    #+#             */
/*   Updated: 2019/05/12 13:49:50 by fgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

static char		*ft_fill(char *buf)
{
	int		i;
	char	*s;

	i = 0;
	while (buf[i] != '\0' && buf[i] != '\n')
		i++;
	s = (char*)malloc(sizeof(char) * i + 1);
	i = 0;
	while (buf[i] != '\0' && buf[i] != '\n')
	{
		s[i] = buf[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

int				get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	int				ret;
	static char		*s;

	if (fd <= -1 || !line || read(fd, buf, 0) < 0)
		return (-1);
	//(*line) =  ft_strdup("");
	(*line) = (((*line) == NULL) ? ft_strdup("") : (*line));
	s = (s == NULL ? ft_strdup("") : s);
	if (s != NULL && s[0] != '\0')
	{
		(*line) = ft_strjoin((*line), ft_fill(s));//ft_fill(s);
		s = ft_strdup(ft_end(s));
		return (get_next_line(fd, line));//return (1);
	}
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		(*line) = ((s[0] == '\0') ? (ft_strjoin((*line), ft_fill(buf))) :
				(ft_strjoin(s, ft_fill(buf))));
		free(s);
		s = ft_strdup(ft_end(buf));
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (ret);
}
