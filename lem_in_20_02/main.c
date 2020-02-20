/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego <ediego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 21:46:43 by fgeorgin          #+#    #+#             */
/*   Updated: 2020/02/17 18:16:58 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_after_bfs(t_map *map, int *way)
{
	if (way[0] == 2147483647)
		ft_exit(map, NULL, 0);
	else
		ft_output_lines(map->head);
}

void		ft_solution(t_map *map, t_room *room)
{
	int			*way;
	t_map		*sh_w;
	t_map		*tmp;
	t_w_and_d	*st;

	way = ft_bfs(map, room[map->start], room[map->start], 0);
	ft_after_bfs(map, way);
	if (map->num_ants > way[0])
	{
		sh_w = ft_copy_map(map);
		tmp = ft_copy_map(map);
		ft_if_n_ways(map, sh_w, tmp);
		st = ft_do_ways_diff(map, sh_w);
		ft_ants_to_ways(map, st);
		ft_free_st(st);
		ft_exit(sh_w, NULL, 1);
		ft_exit(tmp, NULL, 1);
	}
	else
	{
		map->min = 1;
		ft_output_into_bfs(map, 1, way, 2);
		printf("\n");// ft_putchar('\n');
	}
	free(way);
}

int			main(void)
{
	t_map	*map;

	map = (t_map*)ft_memalloc(sizeof(t_map));
	map->out = (t_str*)ft_memalloc(sizeof(t_str));
	map->head = map->out;
	ft_valid(map, 0);
	ft_solution(map, map->room);
	ft_exit(map, NULL, 1);
	return (0);
}
