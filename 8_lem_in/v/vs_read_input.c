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

void	vs_sharp(t_vs *vs, char **line, int *i)
{
	char se;

	if (!ft_strcmp(*line, "##start") || !ft_strcmp(*line, "##end"))
	{
		se = (*line)[2];
		if (!ft_strcmp(*line, "##start"))
			vs->map->ok_s = 'O';
		else if (!ft_strcmp(*line, "##end"))
			vs->map->ok_e = 'O';
		free(*line);
		get_next_line(STDIN_FILENO, &(*line));
		if (*line[0] != 'L')
			vs_the_room(vs, *line, (se == 's' ? 1 : 3), &(*i));
		else
			vs_exit(vs, *line, 0);
	}
}

void	vs_number_of_ants(t_vs *vs, char *line)
{
	if (vs_check_x_y(line) != 0)
	{
		vs->map->num_ants = ft_atoi(line);
		if (vs->map->num_ants <= 0)
			vs_exit(vs, line, 0);
		vs->map->data = 1;
	}
	else
		vs_exit(vs, line, 0);
}

void	vs_the_room(t_vs *vs, char *line, int sea, int *i)
{
	char	**arr;

	arr = ft_strsplit(line, ' ');
	if (arr[3] != NULL || !vs_check_x_y(arr[1]) || !vs_check_x_y(arr[2]) ||
			vs_find_num(vs->map->room, arr[0]) != -1
			|| !vs_coord(vs->map, arr[1], arr[2]))
	{
		vs_free_split(arr);
		vs_exit(vs, line, 0);
	}
	vs->map->room[(*i)].num = (*i);
	vs->map->room[(*i)].name = ft_strdup(arr[0]);
	vs->map->room[(*i)].x = ft_atoi(arr[1]);
	vs->map->room[(*i)].y = ft_atoi(arr[2]);
	if (sea == 1)
		vs->map->start = (*i);
	else if (sea == 3)
		vs->map->end = (*i);
	(*i)++;
	vs->map->data = 2;
	vs_free_split(arr);
}

void	vs_the_links(t_vs *vs, char *line)
{
	char	**arr;
	int		n0;
	int		n1;

	arr = ft_strsplit(line, '-');
	if (!(ft_strchr(line, '-')))
	{
		vs_free_split(arr);
		vs_exit(vs, line, 0);
	}
	n0 = vs_find_num(vs->map->room, arr[0]);
	n1 = vs_find_num(vs->map->room, arr[1]);
	if (arr[2] != NULL || n0 == -1 || n1 == -1 || n0 == n1
	|| !vs_if_l(vs->map, n0, n1))
		vs_exit(vs, line, 0);
	vs_make_link(vs->map, n0, n1);
	vs_make_link(vs->map, n1, n0);
	vs->map->data = 3;
	vs_free_split(arr);
}
