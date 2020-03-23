/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_read_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego <ediego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 13:19:25 by ediego            #+#    #+#             */
/*   Updated: 2020/02/24 19:48:05 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	vs_sharp(t_map *map, char **line, int *i)
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
		if (*line[0] != 'L')
			vs_the_room(map, *line, (se == 's' ? 1 : 3), &(*i));
		else
			vs_exit(map, *line, 0);
	}
}

void	vs_number_of_ants(t_map *map, char *line)
{
	if (vs_check_x_y(line) != 0)
	{
		map->num_ants = ft_atoi(line);
		if (map->num_ants <= 0)
			vs_exit(map, line, 0);
		map->data = 1;
	}
	else
		vs_exit(map, line, 0);
}

void	vs_the_room(t_map *map, char *line, int sea, int *i)
{
	char	**arr;

	arr = ft_strsplit(line, ' ');
	if (arr[3] != NULL || !vs_check_x_y(arr[1]) || !vs_check_x_y(arr[2]) ||
			vs_find_num(map->room, arr[0]) != -1
			|| !vs_coord(map, arr[1], arr[2]))
	{
		vs_free_split(arr);
		vs_exit(map, line, 0);
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
	vs_free_split(arr);
}

void	vs_the_links(t_map *map, char *line)
{
	char	**arr;
	int		n0;
	int		n1;

	arr = ft_strsplit(line, '-');
	n0 = vs_find_num(map->room, arr[0]);
	n1 = vs_find_num(map->room, arr[1]);
	if (arr[2] != NULL || n0 == -1 || n1 == -1 || n0 == n1
	|| !vs_if_l(map, n0, n1))
		vs_exit(map, line, 0);
	if (map->room[n0].level == 1)
		map->room[n1].level = 2;
	if (map->room[n1].level == 1)
		map->room[n0].level = 2;
	vs_make_link(map, n0, n1);
	vs_make_link(map, n1, n0);
	map->data = 3;
	vs_free_split(arr);
}
