/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediego <ediego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 21:46:43 by fgeorgin          #+#    #+#             */
/*   Updated: 2020/03/08 09:25:22 by ediego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_init_map(t_map *map)
{
	int		count;
	t_room	*room;

	count = 0;
	room = map->room;
	while (room[count].name)
		count++;
	map->sum_r = count;
}

void		ft_if_no_way(t_map *map, int *way)
{
	if (way[0] == 2147483647)
	{
		free(way);
		ft_exit(map, NULL, 0);
	}
	else
	{
		free(way);
		ft_output_lines(map->head);
	}
}

void		ft_do_0_var(t_map *map, t_map *sh_w, t_w_and_d *var)
{
	int i;

	i = 0;
	while (i < 100)
	{
		var[i].res = 0;
		i++;
	}
	i = 0;
	while (map->room[i].name)
	{
		map->room[i].ind_out_room = -1;
		sh_w->room[i].ind_out_room = -1;
		i++;
	}
}

void		ft_solution(t_map *map)
{
	int			*way;
	t_map		*sh_w;
	t_w_and_d	var[100];

	sh_w = ft_copy_map(map);
	ft_do_0_var(map, sh_w, var);
	way = NULL;
	while (map->room[map->start].links)
	{
		way = ft_bfs(map, map->room, map->start);
		if (way[0] == 2147483647)
		{
			free(way);
			break ;
		}
		if (ft_find_crossing(sh_w, way) == 1)
			ft_if_cross(map, sh_w, var, way);
		else
			ft_move_sh_w(map, sh_w, way);
		ft_suurballe(map, way);
		free(way);
	}
	ft_if_cross(map, sh_w, var, NULL);
	ft_exit(sh_w, NULL, 1);
	ft_finish_sol(map, var);
}

int			main(void)
{
	t_map	*map;
	int		*val;

	map = (t_map*)ft_memalloc(sizeof(t_map));
	map->out = (t_str*)ft_memalloc(sizeof(t_str));
	map->head = map->out;
	ft_valid(map, 0);
	ft_init_map(map);
	val = ft_bfs(map, map->room, map->start);
	ft_if_no_way(map, val);
	ft_solution(map);
	ft_exit(map, NULL, 1);
	return (0);
}
