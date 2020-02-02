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
		map->num_ants = ft_atoi(line);
		if (map->num_ants <= 0)
			ft_exit(map, line, 0);
		map->data = 1;
	}
	else
		ft_exit(map, line, 0);
}

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

int		ft_if_l(t_map *map, int n0, int n1)
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

void	the_links(t_map *map, char *line)
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

// int		ft_bfs(t_room *room, t_room curr_room, t_room start, t_room end, t_room prev_room, int min)
// {
// 	// printf("name = %s\n", curr_room.name);
// 	t_link *tmp;
// 	tmp = curr_room.links;
// 	int i = 9999999;
// 	int count = 0;
// 	while (tmp)
// 	{
// 		if ((room[tmp->link_num].x == prev_room.x && room[tmp->link_num].y == prev_room.y)
// 		|| (room[tmp->link_num].level == 1))// || (room[tmp->link_num].level == 2 && curr_room.level == 0))
// 			{
// 				tmp = tmp->next;
// 				continue ;
// 			}
// 		// if (curr_room.x == end.x && curr_room.y == end.y)
// 		if (curr_room.level == 3)
// 			return (min);
// 		else
// 			count = ft_bfs(room, room[tmp->link_num], start, end, curr_room, min + 1);
// 		tmp = tmp->next;
// 		if (count < i)
// 			i = count;
// 		// printf("name = %s\n", curr_room.name);
// 	}
// 	return (i);
// }

// int		ft_bfs(t_map *map, t_room curr_room, t_room prev_room, int min)
// {
// 	printf("name = %s\n", curr_room.name);
// 	t_link *tmp;
// 	tmp = curr_room.links;
// 	int i = 9999999;
// 	int count = 0;
// 	while (tmp)
// 	{
// 		if ((map->room[tmp->link_num].x == prev_room.x
// 			&& map->room[tmp->link_num].y == prev_room.y)
// 			|| (map->room[tmp->link_num].level == 1))
// 			{
// 				tmp = tmp->next;
// 				continue ;
// 			}
// 		if (curr_room.num == map->end)
// 			return (min);
// 		else
// 			count = ft_bfs(map, map->room[tmp->link_num], curr_room, min + 1);
// 		tmp = tmp->next;
// 		if (count < i)
// 			i = count;
// 		printf("name = %s\n", curr_room.name);
// 	}
// 	return (i);
// }

// void	ft_solution(t_map *map, t_room *room)
// {
// 	int num = ft_bfs(map, room[map->start], room[map->start], 0);
//     printf("res = %d\n", num);
// }

// t_way	*ft_bfs(t_map *map, t_room curr_room, t_room prev_room, int min)
// {
// 	t_way *room_struct = (t_way*)ft_memalloc(sizeof(t_way));
// 	t_way *count;
// 	t_way *way = (t_way*)ft_memalloc(sizeof(t_way));
// 	room_struct->way = (t_link*)ft_memalloc(sizeof(t_link));
// 	room_struct->way->link_num = curr_room.num;
// 	room_struct->i = 9999999;
	
// 	// printf("name = %s\n", curr_room.name);
// 	t_link *tmp;

// 	tmp = curr_room.links;
// 	while (tmp)
// 	{
// 		if ((map->room[tmp->link_num].x == prev_room.x
// 			&& map->room[tmp->link_num].y == prev_room.y)
// 			|| (map->room[tmp->link_num].level == 1))
// 			{
// 				if (curr_room.num == map->end)
// 				{
// 					way = (t_way*)ft_memalloc(sizeof(t_way));
// 					way->i = min;
// 					way->way = room_struct->way;
// 					return (way);
// 				}
// 				tmp = tmp->next;
// 				continue ;
// 			}
// 		if (curr_room.num == map->end)
// 		{
// 			way = (t_way*)ft_memalloc(sizeof(t_way));
// 			way->i = min;
// 			way->way = room_struct->way;
// 			return (way);
// 		}
// 		else
// 			count = ft_bfs(map, map->room[tmp->link_num], curr_room, min + 1);
// 		tmp = tmp->next;
// 		if (count->i < room_struct->i)
// 		{
// 			room_struct->i = count->i;
// 			room_struct->way->next = count->way;
// 		}
// 		// printf("name = %s\n", curr_room.name);
// 	}
// 	return (room_struct);
// }

// void	ft_solution(t_map *map, t_room *room)
// {
// 	t_way *way;
// 	way = ft_bfs(map, room[map->start], room[map->start], 0);
//     while (way->way->next)
// 	{
// 		printf("%s\n", map->room[way->way->link_num].name);
// 		way->way = way->way->next;
// 	}
// 	printf("%s\n", map->room[way->way->link_num].name);
// }

int		*ft_ret_way(int *way, t_room curr_room, int min)
{
	free(way);
	way = ft_memalloc(sizeof(int) * min + 1);
	way[0] = min;
	way[min + 1] = curr_room.num;
	return (way);
}

int		*ft_bfs(t_map *map, t_room curr_room, t_room prev_room, int min)
{
	int *room_struct;
	int *way;
	t_link *tmp;
	
	tmp = curr_room.links;
	way = ft_memalloc(sizeof(int) * 1);
	way[0] = 2147483647;
	while (tmp)
	{
		if ((map->room[tmp->link_num].x == prev_room.x && map->room[tmp->
		link_num].y == prev_room.y) || (map->room[tmp->link_num].level == 1))
			{
				if (curr_room.num == map->end)
					return (ft_ret_way(way, curr_room, min));
				tmp = tmp->next;
				continue ;
			}
		if (curr_room.num == map->end)
			return (ft_ret_way(way, curr_room, min));
		else
			room_struct = ft_bfs(map, map->room[tmp->link_num], curr_room, min + 1);
		tmp = tmp->next;
		if (room_struct[0] < way[0])
		{
			free(way);
			way = room_struct;
			way[min + 1] = curr_room.num;
		}
		else
			free(room_struct);
	}
	return (way);
}

void	ft_solution(t_map *map, t_room *room)
{
	int *way;
	way = ft_bfs(map, room[map->start], room[map->start], 0);
	printf("min steps to end = %d\n", way[0]);
    int i = 1;
	while (i <= way[0] + 1)
	{
		printf("%s\n", map->room[way[i]].name);
		i++;
	}
	free (way);
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
