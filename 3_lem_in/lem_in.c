/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 19:37:35 by fgeorgin          #+#    #+#             */
/*   Updated: 2019/12/08 19:37:37 by fgeorgin         ###   ########.fr       */
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

long long		ft_atolli(const char *str)
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

int				ft_num_of_digit(char *s)
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

int		check_x_y(char *s)
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

void	number_of_ants(t_map *map, char *line)
{
	if (check_x_y(line) != 0)
	{
		printf("in number_of_ants = %s\n", line);
		map->num_ants = ft_atoi(line);
		if (map->num_ants <= 0)
			ft_exit(map, line, 0);
		map->data = 1;
	}
	else
		ft_exit(map, line, 0);
}

// int		ft_find_hash(char *s)
// {
// 	int i;
// 	int res;

// 	i = 0;
// 	res = 1;
// 	while (s[i] != '\0')
// 	{
// 		res = res * 7 + s[i];
// 		i++;
// 	}
// 	return (res / i * 7);
// }

void	ft_free_split(char **arr)
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

int		ft_find_num(t_room *room, char *arr_n)
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

void	make_link(t_map *map, int n0, int n1)
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

void	the_links(t_map *map, char *line)
{
	char	**arr;
	int		n0;
	int		n1;

	printf("in the_links = %s\n", line);
	arr = ft_strsplit(line, '-');
	n0 = ft_find_num(map->room, arr[0]);
	n1 = ft_find_num(map->room, arr[1]);
	if (arr[2] != NULL || n0 == -1 || n1 == -1 || n0 == n1)
		ft_exit(map, line, 0);
	make_link(map, n0, n1);
	make_link(map, n1, n0);
	map->data = 3;
	ft_free_split(arr);
	// l0 = (t_link*)ft_memalloc(sizeof(t_link));
	// l0->link_num = n1;
	// temp0 = map->room[n0].links;
	// while (map->room[n0].links != NULL)
	// 	map->room[n0].links = map->room[n0].links->next;
	// map->room[n0].links = l0;
	// map->room[n0].links = temp0;
	// l1 = (t_link*)ft_memalloc(sizeof(t_link));
	// l1->link_num = n0;
	// while (map->room[n1].links != NULL)
	// 	map->room[n1].links = map->room[n1].links->next;
	// map->room[n1].links = l1;
	
	// n0 = ft_find_hash(arr[0]);
	// n1 = ft_find_hash(arr[1]);
	// if (arr[2] != NULL || !(map->room[n0].name) || !(map->room[n1].name))
	// 	ft_exit(map, line, 0);
	// if (!map->room[n0].links)
	// 	map->room[n0].links = (char**)ft_memalloc(sizeof(char*) * 4000);
	// // if (map->room[n0].curr_link == 0)
	// // 	map->hash_of_rooms[map->curr_hash++] = n0;
	// map->room[n0].links[map->room[n0].curr_link] = ft_strdup(arr[1]);
	// (map->room[n0].curr_link)++;
	// if (!map->room[n1].links)
	// 	map->room[n1].links = (char**)ft_memalloc(sizeof(char*) * 4000);
	// // if (map->room[n1].curr_link == 0)
	// 	// map->hash_of_rooms[map->curr_hash++] = n1;
	// map->room[n1].links[map->room[n1].curr_link] = ft_strdup(arr[0]);
	// (map->room[n1].curr_link)++;
	// map->data = 3;
	// ft_free_split(arr);
}

int		ft_coord(t_map *map, char *s1, char *s2)
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

void	the_room(t_map *map, char *line, int sea, int *i)
{
	char	**arr;

	printf("in the_room = %s\n", line);//fdsnioghueowijhgueijewr
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
	(*i)++;
	if (sea == 0)
		map->start = (*i) - 1;
	else if (sea == 1)
		map->end = (*i) - 1;
	map->data = 2;
	ft_free_split(arr);
	// n = ft_find_hash(arr[0]);
	// if (!(map->room[n].name))
	// 	map->hash_of_rooms[map->curr_hash++] = n;
	// map->room[n].name = ft_strdup(arr[0]);
	// map->room[n].x = ft_atoi(arr[1]);
	// map->room[n].y = ft_atoi(arr[2]);
	// if (sea == 0)
	// 	map->start = n;
	// else if (sea == 1)
	// 	map->end = n;
	// map->data = 2;
	// ft_free_split(arr);
}

void	ft_sharp(t_map *map, char **line, int fd, int *i)
{
	char se;

	printf("in ft_sharp = %s\n", *line);
	if (!ft_strcmp(*line, "##start") || !ft_strcmp(*line, "##end"))
	{
		se = (*line)[2];
		if (!ft_strcmp(*line, "##start"))
			map->ok_s = 'O';
		else if (!ft_strcmp(*line, "##end"))
			map->ok_e = 'O';
		free(*line);
		get_next_line(fd, &(*line));//dwqqwdqwdqwdwqdqwdqwdqwdqw
		if (*line[0] != 'L')
			the_room(map, *line, (se == 's' ? 0 : 1), &(*i));/* 0 - start, 1 - end, 2 - another */
		else
			ft_exit(map, *line, 0);
	}
}

void	ft_valid(t_map *map, int i)
{
	char	*line;

	int fd = open("subject.map", O_RDONLY); //   ./archive/map subject.map
	while (get_next_line(fd, &line))
	{
		if (map->data == 0 && ft_strchr("0123456789-", line[0]))
			number_of_ants(map, line);
		else if (line[0] != '\0' && line[0] == '#')
			ft_sharp(map, &line, fd, &i); // fwegrrfwedfergethryjhtgrfgeth
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
	if (map->data != 3 || map->ok_s != 'O' || map->ok_e != 'O')
		ft_exit(map, NULL, 0);
}

void	ft_bfs(t_room *room, t_room curr_room, t_room end, t_room prev_room)
{
	printf("name = %s\n", curr_room.name);
	while (curr_room.links)
	{
		if (room[curr_room.links->link_num].x == prev_room.x
			&& room[curr_room.links->link_num].y == prev_room.y)
			curr_room.links = curr_room.links->next;
		if (curr_room.x == end.x && curr_room.y == end.y)
			break ;
		else
			ft_bfs(room, room[curr_room.links->link_num], end, curr_room);
		curr_room.links = curr_room.links->next;
	}
}

void	ft_solution(t_map *map, t_room *room)
{
	ft_bfs(room, room[map->start], room[map->end], room[map->end]);
}

int		main()
{
	t_map	*map;

	map = (t_map*)ft_memalloc(sizeof(t_map));
	ft_valid(map, 0);
	ft_solution(map, map->room);
	ft_exit(map, NULL, 1);
	return (0);
}
