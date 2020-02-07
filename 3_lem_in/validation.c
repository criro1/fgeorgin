/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 17:49:24 by fgeorgin          #+#    #+#             */
/*   Updated: 2020/02/07 17:50:20 by fgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_exit(t_map *map, char *line, int err)
{
	int i;

	i = 0;
	while (map->room[i].name)
	{
		while (map->room[i].links)
		{
			free(map->room[i].links);
			map->room[i].links = map->room[i].links->next;
		}
		free(map->room[i].name);
		i++;
	}
	free(map);
	if (line)
		free(line);
	if (err == 0)
		write(2, "Error\n", 6);
	if (err == 0)
		exit(0);
}

static long long		ft_atolli(const char *str)
{
	int			i;
	long int	num;
	int			s;

	i = 0;
	num = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	s = ((str[i] == '-') ? -1 : 0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return ((s == -1) ? -num : num);
}

static int			ft_num_of_digit(char *s)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (ft_isdigit(s[i]))
	{
		res++;
		i++;
	}
	return (res);
}

static int		check_x_y(char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	if (ft_num_of_digit(s) > 10 || ft_atolli(s) >= 2147483648)
		return (0);
	while (s[i] != '\0')
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	if (s[0] == '\0')
		return (0);
	return (1);
}

static void	number_of_ants(t_map *map, char *line)
{
	if (check_x_y(line) != 0)
	{
		map->num_ants = ft_atoi(line);
		if (map->num_ants <= 0)
			ft_exit(map, line, 0);
		map->data = 1;
	}
	else
		ft_exit(map, line, 0);
}

static void	ft_free_split(char **arr)
{
	int 	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static int		ft_find_num(t_room *room, char *arr_n)
{
	int 	i;

	i = -1;
	while (room[++i].name)
	{
		if (room[i].name[0] == arr_n[0] && room[i].name[1] == arr_n[1])
			if (!(ft_strcmp(room[i].name, arr_n)))
				return (i);
	}
	return (-1);
}

static void	make_link(t_map *map, int n0, int n1)
{
	t_link	*l;
	t_link	*temp;

	l = (t_link*)ft_memalloc(sizeof(t_link));
	l->link_num = n1;
	if (map->room[n0].links == NULL)
	{
		map->room[n0].links = l;
		return ;
	}
	temp = map->room[n0].links;
	while (map->room[n0].links->next != NULL)
		map->room[n0].links = map->room[n0].links->next;
	map->room[n0].links->next = l;
	map->room[n0].links = temp;
}

static int		ft_if_l(t_map *map, int n0, int n1)
{
	t_link *l;

	l = map->room[n0].links;
	while (l)
	{
		if (l->link_num == n1)
			return (0);
		l = l->next;
	}
	return (1);
}

static void	the_links(t_map *map, char *line)
{
	char	**arr;
	int		n0;
	int		n1;

	arr = ft_strsplit(line, '-');
	n0 = ft_find_num(map->room, arr[0]);
	n1 = ft_find_num(map->room, arr[1]);
	if (arr[2] != NULL || n0 == -1 || n1 == -1 || n0 == n1 || !ft_if_l(map, n0, n1))
		ft_exit(map, line, 0);
	if (map->room[n0].level == 1)
		map->room[n1].level = 2;
	if (map->room[n1].level == 1)
		map->room[n0].level = 2;
	make_link(map, n0, n1);
	make_link(map, n1, n0);
	map->data = 3;
	ft_free_split(arr);
}

static int		ft_coord(t_map *map, char *s1, char *s2)
{
	int i;
	int x;
	int y;

	x = ft_atoi(s1);
	y = ft_atoi(s2);
	i = 0;
	while (map->room[i].name)
	{
		if (map->room[i].x == x && map->room[i].y == y)
			return (0);
		i++;
	}
	return (1);
}

static void	the_room(t_map *map, char *line, int sea, int *i)
{
	char	**arr;

	arr = ft_strsplit(line, ' ');
	if (arr[3] != NULL || !check_x_y(arr[1]) || !check_x_y(arr[2]) ||
			ft_find_num(map->room, arr[0]) != -1 || !ft_coord(map, arr[1], arr[2]))
	{
		ft_free_split(arr);
		ft_exit(map, line, 0);
	}
	map->room[(*i)].num = (*i);
	map->room[(*i)].name = ft_strdup(arr[0]);
	map->room[(*i)].x = ft_atoi(arr[1]);
	map->room[(*i)].y = ft_atoi(arr[2]);
	if (sea == 1)
	{
		map->start = (*i);
		map->room[(*i)].level = 1;
	}
	else if (sea == 3)
		map->end = (*i);
	(*i)++;
	map->data = 2;
	ft_free_split(arr);
}

static void	ft_sharp(t_map *map, char **line, int fd, int *i)
{
	char se;

	if (!ft_strcmp(*line, "##start") || !ft_strcmp(*line, "##end"))
	{
		se = (*line)[2];
		if (!ft_strcmp(*line, "##start"))
			map->ok_s = 'O';
		else if (!ft_strcmp(*line, "##end"))
			map->ok_e = 'O';
		free(*line);
		get_next_line(fd, &(*line));
		if (*line[0] != 'L')
			the_room(map, *line, (se == 's' ? 1 : 3), &(*i));/* 1 - start, 2 - another, 3 - end*/
		else
			ft_exit(map, *line, 0);
	}
}

void	ft_valid(t_map *map, int i)
{
	char	*line;

	int fd = open("subject.map", O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (map->data == 0 && ft_strchr("0123456789-", line[0]))
			number_of_ants(map, line);
		else if (line[0] != '\0' && line[0] == '#')
			ft_sharp(map, &line, fd, &i);
		else if (line[0] != '\0' && line[0] != 'L'
				&& (map->data == 3 || ft_strchr(line, '-')))
			the_links(map, line);
		else if (line[0] != '\0' && line[0] != 'L'
				&& (map->data == 1 || map->data == 2))
			the_room(map, line, 2, &i);/* 0 - start, 1 - end, 2 - another */
		else
			ft_exit(map, line, 0);
		free(line);
	}
	if (map->data != 3 || map->ok_s != 'O' || map->ok_e != 'O' || i < 2)
		ft_exit(map, NULL, 0);
}
