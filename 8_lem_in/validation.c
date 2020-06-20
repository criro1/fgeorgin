/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego <ediego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 17:49:24 by fgeorgin          #+#    #+#             */
/*   Updated: 2020/03/08 17:52:13 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		number_of_ants(t_map *map, char *line)
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

void		ft_sharp(t_map *map, char **line, int *i)
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
		get_next_line(STDIN_FILENO, &(*line));
		map->out->line = ft_strdup(*line);
		map->out->next = (t_str*)ft_memalloc(sizeof(t_str));
		map->out = map->out->next;
		if (*line[0] != 'L')
			the_room(map, *line, (se == 's' ? 1 : 3), &(*i));
		else
			ft_exit(map, *line, 0);
	}
}

void		the_links(t_map *map, char *line)
{
	char	**arr;
	int		n0;
	int		n1;

	arr = ft_strsplit(line, '-');
	if (!(ft_strchr(line, '-')))
	{
		ft_free_split(arr);
		ft_exit(map, line, 0);
	}
	n0 = ft_find_num(map->room, arr[0]);
	n1 = ft_find_num(map->room, arr[1]);
	if (arr[2] != NULL || n0 == -1 || n1 == -1
		|| n0 == n1 || !ft_if_l(map, n0, n1))
	{
		ft_free_split(arr);
		ft_exit(map, line, 0);
	}
	make_link(map, n0, n1);
	make_link(map, n1, n0);
	map->data = 3;
	ft_free_split(arr);
}

void		the_room(t_map *map, char *line, int sea, int *i)
{
	char	**arr;

	arr = ft_strsplit(line, ' ');
	if (arr[3] != NULL || !check_x_y(arr[1]) || !check_x_y(arr[2])
		|| ft_find_num(map->room, arr[0]) != -1
				|| !ft_coord(map, arr[1], arr[2]))
	{
		ft_free_split(arr);
		ft_exit(map, line, 0);
	}
	map->room[(*i)].num = (*i);
	map->room[(*i)].name = ft_strdup(arr[0]);
	map->room[(*i)].x = ft_atoi(arr[1]);
	map->room[(*i)].y = ft_atoi(arr[2]);
	map->room[(*i)].ind_out_room = -1;
	if (sea == 1)
		map->start = (*i);
	else if (sea == 3)
		map->end = (*i);
	(*i)++;
	map->data = 2;
	ft_free_split(arr);
}

void		ft_valid(t_map *map, int i)
{
	char	*line;

	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		map->out->line = ft_strdup(line);
		map->out->next = (t_str*)ft_memalloc(sizeof(t_str));
		map->out = map->out->next;
		if (map->data == 0 && ft_strchr("0123456789-", line[0]))
			number_of_ants(map, line);
		else if (line[0] != '\0' && line[0] == '#')
			ft_sharp(map, &line, &i);
		else if (line[0] != '\0' && line[0] != 'L'
				&& (map->data == 3 || ft_strchr(line, '-')))
			the_links(map, line);
		else if (line[0] != '\0' && line[0] != 'L'
				&& (map->data == 1 || map->data == 2))
			the_room(map, line, 2, &i);
		else
			ft_exit(map, line, 0);
		free(line);
	}
	if (map->data != 3 || map->ok_s != 'O' || map->ok_e != 'O' || i < 2
		|| map->num_ants <= 0)
		ft_exit(map, NULL, 0);
}
