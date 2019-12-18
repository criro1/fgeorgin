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
	int j;

	i = 0;
	while (i < map->curr_hash)
	{
		j = 0;
		if (map->room[map->hash_of_rooms[i]].links)
			while (map->room[map->hash_of_rooms[i]].links[j])
			{
				free(map->room[map->hash_of_rooms[i]].links[j]);
				j++;
			}
		free(map->room[map->hash_of_rooms[i]].name);
		free(map->room[map->hash_of_rooms[i]].links);
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

int		check_x_y(char *s)
{
	int i;

	i = 0;
	if (!s)
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

int		ft_find_hash(char *s)
{
	int i;
	int res;

	i = 0;
	res = 1;
	while (s[i] != '\0')
	{
		res = res * 7 + s[i];
		i++;
	}
	return (res / i * 7);
}

void	ft_free_split(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	the_links(t_map *map, char *line)
{
	char	**arr;
	int		n0;
	int 	n1;

	printf("in the_links = %s\n", line);
	arr = ft_strsplit(line, '-');
	n0 = ft_find_hash(arr[0]);
	n1 = ft_find_hash(arr[1]);
	if (arr[2] != NULL || !(map->room[n0].name) || !(map->room[n1].name))
		ft_exit(map, line, 0);
	if (!map->room[n0].links)
		map->room[n0].links = (char**)ft_memalloc(sizeof(char*) * 4000);
	// if (map->room[n0].curr_link == 0)
	// 	map->hash_of_rooms[map->curr_hash++] = n0;
	map->room[n0].links[map->room[n0].curr_link] = ft_strdup(arr[1]);
	(map->room[n0].curr_link)++;
	if (!map->room[n1].links)
		map->room[n1].links = (char**)ft_memalloc(sizeof(char*) * 4000);
	// if (map->room[n1].curr_link == 0)
		// map->hash_of_rooms[map->curr_hash++] = n1;
	map->room[n1].links[map->room[n1].curr_link] = ft_strdup(arr[0]);
	(map->room[n1].curr_link)++;
	map->data = 3;
	ft_free_split(arr);
}

void	the_room(t_map *map, char *line, int sea)
{
	char	**arr;
	int		n;

	printf("in the_room = %s\n", line);//fdsnioghueowijhgueijewr
	arr = ft_strsplit(line, ' ');
	if (arr[3] != NULL || !check_x_y(arr[1]) || !check_x_y(arr[2]))
	{
		ft_free_split(arr);
		ft_exit(map, line, 0);
	}
	n = ft_find_hash(arr[0]);
	if (!(map->room[n].name))
		map->hash_of_rooms[map->curr_hash++] = n;
	map->room[n].name = ft_strdup(arr[0]);
	map->room[n].x = ft_atoi(arr[1]);
	map->room[n].y = ft_atoi(arr[2]);
	if (sea == 0)
		map->start = n;
	else if (sea == 1)
		map->end = n;
	map->data = 2;
	ft_free_split(arr);
}

void	ft_sharp(t_map *map, char **line, int fd)
{
	char se;

	printf("in ft_sharp = %s\n", *line);
	if (!ft_strcmp(*line, "##start") || !ft_strcmp(*line, "##end"))
	{
		se = (*line)[2];
		free(*line);
		get_next_line(fd, &(*line));//dwqqwdqwdqwdwqdqwdqwdqwdqw
		if (*line[0] != 'L')
			the_room(map, *line, (se == 's' ? 0 : 1));/* 0 - start, 1 - end, 2 - another */
		else
			ft_exit(map, *line, 0);
	}
}

void	ft_valid(t_map *map)
{
	char	*line;

	int fd = open("subject.map", O_RDONLY); //ewfkjoghruirejighqgrh0hrgqie
	while (get_next_line(fd, &line))
	{
		if (map->data == 0 && ft_strchr("0123456789-", line[0]))
			number_of_ants(map, line);
		else if (line[0] != '\0' && line[0] == '#')
			ft_sharp(map, &line, fd); // fwegrrfwedfergethryjhtgrfgeth
		else if (line[0] != '\0' && line[0] != 'L'
			&& (map->data == 3 || ft_strchr(line, '-')))
			the_links(map, line);
		else if (line[0] != '\0' && line[0] != 'L'
			&& (map->data == 1 || map->data == 2))
			the_room(map, line, 2);/* 0 - start, 1 - end, 2 - another */
		else
			ft_exit(map, line, 0);
		free(line);
	}
	if (map->data != 3 || !map->start || !map->end)
		ft_exit(map, NULL, 0);
}

void	ft_bfs(int curr, int end, t_map *map, int res)
{
	int i;

	i = 0;
	if (curr == end)
		return (res);
	else if ()
}

void	ft_solution(t_map *map)
{
	ft_bfs(map->start, map->end, map, 0);
}

int		main()
{
	t_map	*map;

	map = (t_map*)ft_memalloc(sizeof(t_map));
	ft_valid(map);
	ft_solution(map);
	ft_exit(map, NULL, 1);
	return (0);
}
